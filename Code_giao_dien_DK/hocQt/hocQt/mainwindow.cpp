#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtCore>
#include<opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include <comserial.h>





using namespace std;
using namespace cv;




// cửa sổ khởi động khi vào

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    devserial = new QSerialPort(this);
    procSerial = new comserial(devserial);
    QStringList DispSerial = procSerial->ConnectedDevices();
    ui->comboBox->addItems(DispSerial);
    if(DispSerial.length()>0){

        ui->Connect->setEnabled(true);
        ui->textEdit->append("### Serial port ready for use.");
    }
    else {ui->textEdit->append("No serial ports were detected!");}

connect(devserial, SIGNAL(readyRead()),this,SLOT(ReadData()));
//"http://192.168.3.111:4747/video"

    capwebcam.open("http://192.168.43.42:4747/video");
    if(!capwebcam.isOpened()){
        ui->textEdit->setText("Error: capWebcam not accessed successfully ");
        return;

    }


    test = false;
    Center_10 = 0;
    Center_20 = 0;
    tmrTimer =new QTimer(this);
    Timer_Process =new QTimer(this);

    connect(ui->detection,SIGNAL(clicked()),this,SLOT(showMat()));
    connect(tmrTimer,SIGNAL(timeout()),this,SLOT(videoOriginal()));// gọi hàm xử lý ảnh trong
    tmrTimer ->start(30);
    Timer_Process->start(30);




}

MainWindow::~MainWindow()
{
    delete ui;
}


// hiển thị hình ảnh

QImage MainWindow::convertOpenCVMatToQtQImage(cv::Mat mat) {
    if(mat.channels() == 1) {                   // if grayscale image
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);     // tạo khung ảnh xám
    } else if(mat.channels() == 3) {            // if 3 channel color image
        cv::cvtColor(mat, mat, COLOR_BGR2RGB);     // invert BGR to RGB
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);       // tạo khung ảnh grb
    } else {

    }
    return QImage();        // return a blank QImage if the above did not work
}


// tạo hình bao


// video nguyên bản
void MainWindow::videoOriginal(){



    capwebcam.read(matOriginal);


    QImage qimgOriginal=convertOpenCVMatToQtQImage(matOriginal);// biên đổi ảnh sáng kiể dữ liêu QImage

    ui->imgOriginal->setPixmap(QPixmap::fromImage(qimgOriginal));
    // hiển thị dữ liệu vừa biến đổi lên label imgOriginal


}

// nhấn nút chạy ảnh
void MainWindow:: showMat(){
    if(!test){
    //cout <<"den day";
    test = true;
    Timer_Process->start();
    connect(Timer_Process,SIGNAL(timeout()),this,SLOT(dst_Mat()));
    }else{
        test=false;
        Timer_Process->stop();
    }

}



// .............Các hàm liên quan đến Serial ..............

void MainWindow::on_Connect_clicked()// kết nối với cổng port
{
    bool statusOpenSerial;
    statusOpenSerial = procSerial->Connect(ui->comboBox->currentText(),ui->comboBox_2->currentText().toInt());
    ui->comboBox->currentText();
    if(statusOpenSerial) {
        ui->Disconnect->setEnabled(true);
        ui->Connect->setEnabled(false);
        ui->textEdit->append("Kết Nối Thành Công");
        ui->comboBox->addItem(QString::number(ui->comboBox->currentText().toInt()));
        ReadData();

    }
    else {
        ui->textEdit->append("Kết Nối Không Thành Công");
    }
}

void MainWindow::on_Disconnect_clicked() // thoát kết nối với cổng port
{
   bool statusCloseSerial;
   statusCloseSerial = procSerial->Disconnect();
   if(statusCloseSerial){
       ui->Disconnect->setEnabled(false);
       ui->Connect->setEnabled(true);
       ui->textEdit->append("Ngắt Kết Nối");
   }else {
ui->textEdit->append("Không Ngắt được Kết Nối");
}
}
void MainWindow::ReadData() // đọc giá trị từ cổng port
{
    QString data = procSerial->ReadPort();
    ui->textEdit->append(data);

}
void MainWindow::WriteData(const QByteArray data) // gửi giá trị từ cổng port
{
    procSerial->Write(data);
}

// ......kết thúc hàm liên quan với serial

// hàm bật tắt chế độ

void MainWindow::on_btnPauseOrResume_clicked()
{ if(Timer_Process->isActive()){
        Timer_Process->stop();
        ui->btnPauseOrResume->setText("Dừng chế độ xử lý ");

    }
    else{
        Timer_Process->start();
         ui->btnPauseOrResume->setText("Bật chế độ xử lý ");
    }


}


void MainWindow::on_Len_clicked()
{
}
//...........tìm hướng di chuyển của đường.....


// tìm Xcenter
int Xcenter_M(Mat img) {

    vector<int>tong;

    for (int i = 0; i < img.cols; i++) {
        int Sum_0 = 0;
        tong.resize(i + 1);
        for (int j = 0; j < img.rows; j++) {
            Sum_0 += (int)img.at<uchar>(j, i);
        }
        tong[i] = Sum_0;
        //cout << Sum_0 << " "<<i<<" 1 ";

    }

    float S_1 = 0, S_2 = 0;
    for (int i = 0; i < img.cols; i++) {
        S_1 =S_1+  (tong[i] * i);
        S_2 += tong[i];
    }

    return S_1 / S_2;
}

//.. ........xử lý đường đi..............
Mat Fill_Poly(Mat input, vector<Point> vitri, String data,Scalar color={ 255,255,255 }) { // tạo ra poly màu
    Mat output;
    if (data == "3") {
        output = Mat::zeros(input.size(), CV_8UC3);
        int num = (int)vitri.size();
        const Point* pt4 = &(vitri[0]);
        fillPoly(output, &pt4, &num, 1, color, 8);
    }
    else if (data == "1") {
        output = Mat::zeros(input.size(), CV_8UC1);
        int num = (int)vitri.size();
        const Point* pt4 = &(vitri[0]);
        fillPoly(output, &pt4, &num, 1, color, 8);
    }

    return output;
};

     // hàm tìm ra giá trị A và B của các đường
struct R_L {
    // có vạch ko
    bool trai;
    bool phai;
    //
    vector < vector<float>> lineLeft;
    vector < vector<float>> lineRight;


    //giá trị của hàm đường thẳng

    float Average_A;

    float Average_X;

    float  B;

    ;
};
//đường thẳng X= const
R_L Const_L(vector < float> line) {
    R_L L;
    L.Average_A = line[4];
    L.Average_X = line[0];
    L.B = line[0];
    return L;

}
// hàm phân loại các kẻ đường vạch

R_L Right_Left(vector<Vec4f> linesP) {
    R_L Line_R_L;

    Line_R_L.trai = false;
    Line_R_L.phai = false;

    int CounterLeft = 0;
    int CounterRight = 0;

    //

    for (int i = 0; i < linesP.size(); i++)
    {

        float x1 = linesP[i][0];
        float y1 = linesP[i][1];
        float x2 = linesP[i][2];
        float y2 = linesP[i][3];



        float lineLength = pow(pow(y2 - y1, 2) + pow(x2 - x1, 2), 0.5);

        if (lineLength > 15) {
            if (x1 != x2) {
                float a = (y2 - y1) / (x2 - x1);// hệ số góc

                // đường bên phải
                if (a > 0) {
                    float tanTheTa = atan(abs(y1 - y2) / abs(x1 - x2));
                    //cout << "tan= " << tanTheTa << endl;
                    float angle = tanTheTa * 180 / CV_PI;

                    // lọc loại các đường ngang và thẳng đứng
                    if (abs(angle) < 85 && abs(angle) > 15) {
                        Line_R_L.lineRight.resize(CounterRight+1);
                        Line_R_L.lineRight[CounterRight].resize(5);
                        Line_R_L.lineRight[CounterRight][0] = x1;
                        Line_R_L.lineRight[CounterRight][1] = y1;
                        Line_R_L.lineRight[CounterRight][2] = x2;
                        Line_R_L.lineRight[CounterRight][3] = y2;
                        Line_R_L.lineRight[CounterRight][4] = -a;

                        Line_R_L.phai = true;

                        CounterRight++;
                    }



                }

                // đường bên trái

                if (a < 0) {
                    float tanTheTa = atan(abs(y1 - y2) / abs(x1 - x2));
                    //cout << "tan= " << tanTheTa << endl;
                    float angle = (tanTheTa) * 180 / CV_PI;

                    // lọc loại các đường ngang và thẳng đứng
                    if (abs(angle) < 85 && abs(angle) > 15) {
                        Line_R_L.lineLeft.resize((CounterLeft)+1);
                        Line_R_L.lineLeft[CounterLeft].resize(5);
                        Line_R_L.lineLeft[CounterLeft][0] = x1;
                        Line_R_L.lineLeft[CounterLeft][1] = y1;
                        Line_R_L.lineLeft[CounterLeft][2] = x2;
                        Line_R_L.lineLeft[CounterLeft][3] = y2;
                        Line_R_L.lineLeft[CounterLeft][4] = -a;

                        Line_R_L.trai = true;

                        CounterLeft++;
                    }



                }

            }
        }
    }

    return Line_R_L;

};


// hàm tìm giá trị của A và B

R_L A_B(Mat src, vector <vector<float>> line ) {
    R_L A_B;

    ///// lấy các hệ số góc của đường
    vector<float> A;
    for (int i = 0; i < line.size(); i++) {
        A.push_back(line[i][4]);

    }
    // 1 sắp xếp dãy hệ số góc của đường
    sort(A.begin(), A.end());

    // 2  tìm median của dãy hệ số góc của đường

    int Mid_A;
    float Median_A;
    if (A.size() % 2 == 0) {
        Mid_A = A.size() / 2;
        Median_A = (A[Mid_A - 1] + A[Mid_A]) / 2;
    }
    else {
        Mid_A = A.size() / 2;
        Median_A = A[Mid_A];
    }

    //// 3  tìm các hệ số góc của đường  thuộc tập hợp
    vector <float> A_PhuHop;
    float Sum_A = 0;
    for (size_t i = 0; i < A.size(); i++) {
        if (abs(A[i] - Median_A) < 4) {
            A_PhuHop.push_back(A[i]);
            Sum_A = Sum_A + A[i];

        }
    }
    //// tính giá trị trung bình từ mảng hệ số phù hợp của đường
    A_B.Average_A = Sum_A / A_PhuHop.size();

    /////
    //////// tìm X khi Y=0 của đường phải xoay y xuống dưới

    ////1 tìm các X theo a khi Y max
    vector<float> X_below;

    for (int i = 0; i < line.size(); i++) {
        float x1 = line[i][0];
        float y1 = src.rows - line[i][1];
        float a = line[i][4];
        float b = y1 - x1 * a;
        float X_low = -b / a;
        X_below.push_back(X_low);
        //cout << " X_below_Right  " << X_below << endl;
    }
    ////2 sắp xếp các X  khi Y max
    sort(X_below.begin(), X_below.end());

    ////3 tìm giá trị Median của dãy X khi Y max

    int Mid_X;
    float Median_X;
    if (X_below.size() % 2 == 0) {
        Mid_X = X_below.size() / 2;
        Median_X = (X_below[Mid_X - 1] + X_below[Mid_X]) / 2;
    }
    else {
        Mid_X = X_below.size() / 2;
        Median_X = X_below[Mid_X];
    }

    //4 tìm các giá trị X phù hợp với Median X khi Y max
    vector <float> X_below_PhuHop;
    float Sum_X = 0;
    for (size_t i = 0; i < X_below.size(); i++) {
        if (abs(X_below[i] - Median_X) < 4) {
            X_below_PhuHop.push_back(X_below[i]);
            Sum_X = Sum_X + X_below[i];
        }
    }
    //// tính giá trị trung bình của X khi Y max
    A_B.Average_X = Sum_X / X_below_PhuHop.size();
    //// B của đường phải

    A_B.B = -A_B.Average_A * A_B.Average_X;

    return A_B;
}




void MainWindow:: dst_Mat(){ // hàm main chính
    //tạo con trỏ dư lieu
    vector<int> vachduong{0,255,0,48,179,255 };

    //
    capwebcam.read(matOriginal1);
    Mat  gray, blur, matThershold, canny, img, img1, dst, dst_canny, dst2, imgWarp,imgWarp1, over,matpoly;


    vector<Point> diem{ {0, 150},{640, 150},{640, matOriginal1.rows},{0,matOriginal1.rows} };
            // tạo mask3

    img1 =Fill_Poly(matOriginal1, diem, "1" );
            //xử lý src
    //cv::bitwise_and(matOriginal1, img1, dst_canny);


    GaussianBlur(matOriginal1, blur, Size(3, 3), 3, 3);
    cvtColor(blur, gray, COLOR_BGR2HSV);
    Scalar upper(vachduong[1], vachduong[3], vachduong[5]);
    Scalar lower(vachduong[0], vachduong[2], vachduong[4]);

     inRange(gray, lower, upper, canny);
        // ghép ảnh canny + img1
    bitwise_and(canny, img1, dst_canny);


    // lọc các đường thẳng
    vector<Vec4f> linesP;
    HoughLinesP(dst_canny, linesP, 1, 3.1412 / 180, 100, 1, 5);

    // xét trị trí của vạch kẻ đường và vẽ vạch
    R_L *line_R_L = new R_L;
             *line_R_L = Right_Left(linesP);

            if (line_R_L->phai == false && line_R_L->trai == false) {
               // waitKey(33);
                QString cmd ="0";
                WriteData(cmd.toUtf8());

                delete line_R_L;
                cout << "ketthuc";
                return;
            }
            // nêu  ko thay 2 duong
            vector < float> trai {2,0,2,480,0} ;
            vector <float> phai {638,0,638,480,0} ;
            R_L* line_A_B_Left = new R_L;
            R_L* line_A_B_Right = new R_L;
            int Value_x_Left;
            int Value_x_Right;
             int y = 150;
            ///
            if (line_R_L->phai == false) {
                *line_A_B_Left = A_B(matOriginal1, line_R_L->lineLeft);
                //cout << "phải";
                *line_A_B_Right = Const_L(phai);
                // Ptrinh đường trái : Y =Avergage_A_Left* X + B_Left

            // tọa đội cuối của đường phải (Y=src.rows X= Average_X_Right)

            //// tìm giá trị X trái và phải tại Y tọa độ 560

                //	// giá trị X trái tại Y tọa độ 240
                Value_x_Left = ((matOriginal1.rows - y) - line_A_B_Left->B) / line_A_B_Left->Average_A;
                Value_x_Right = line_A_B_Right->B;

            }
            // khong thay duong phai
            else if (line_R_L->trai == false) {
                //cout << "trai";
                *line_A_B_Right = A_B(matOriginal1, line_R_L->lineRight);
                *line_A_B_Left = Const_L(trai);
                // Ptrinh đường trái : Y =Avergage_A_Left* X + B_Left

            // tọa đội cuối của đường phải (Y=src.rows X= Average_X_Right)

            // tìm giá trị X trái và phải tại Y tọa độ 560

                //	// giá trị X phải tại Y tọa độ 240
                 Value_x_Right = ((matOriginal1.rows - y) - line_A_B_Right->B) / line_A_B_Right->Average_A;
                //
                 Value_x_Left = line_A_B_Left->B;
            }
            // ko thay duong trai
            else if (line_R_L->phai == true && line_R_L->trai == true)
                // Xét đường bên trái

            {
                *line_A_B_Left = A_B(matOriginal1, line_R_L->lineLeft);

                // Ptrinh đường Phải : Y =Avergage_A_Right* X + B_Right

                // tọa đội cuối của đường trái (Y=src.rows X= Average_X_Left)

                // Xét đường bên phải

                *line_A_B_Right = A_B(matOriginal1, line_R_L->lineRight);
                // Ptrinh đường trái : Y =Avergage_A_Left* X + B_Left

            // tọa đội cuối của đường phải (Y=src.rows X= Average_X_Right)

            //tìm giá trị X trái và phải tại Y tọa độ 240

                //	// giá trị X trái tại Y tọa độ 240
                 Value_x_Left = ((matOriginal1.rows - y) - line_A_B_Left->B) / line_A_B_Left->Average_A;
                //	// giá trị X phải tại Y tọa độ 240
                 Value_x_Right = ((matOriginal1.rows - y) - line_A_B_Right->B) / line_A_B_Right->Average_A;

           }

            // VẼ DUONG
          /*  matline = Mat::zeros(matOriginal1.size(), CV_8UC3);
            //cout << Value_x_Left << " " << Value_x_Right << " " << line_A_B_Right->Average_X << " " << line_A_B_Left->Average_X << endl;
            line(matline, Point(line_A_B_Left->Average_X, matOriginal1.rows), Point(Value_x_Left, 240), Scalar(0, 0, 255), 4);
            //đường phải

            line(matline, Point(line_A_B_Right->Average_X, matOriginal1.rows), Point(Value_x_Right, 240), Scalar(0, 0, 255), 4);
            addWeighted(matOriginal1, 0.8, matline, 1, 0.0,matOriginal1 );*/
            // tô màu phần đường
  int *x = new int[4];
       x[0] = Value_x_Left;
       x[1] = Value_x_Right;
       x[2] = line_A_B_Right->Average_X;
       x[3] = line_A_B_Left->Average_X;

     vector<Point> hinh_bao{ {x[0], y},
                             {x[1], y},
                             {x[2], matOriginal1.rows},
                             {x[3], matOriginal1.rows} };


     Scalar Blue(237, 96, 61);
     Scalar white(255, 255, 255);
     matpoly = Fill_Poly(matOriginal1, hinh_bao, "3", Blue );
     over =Fill_Poly(matOriginal1,hinh_bao,"1",white);
     addWeighted(matOriginal1, 0.8, matpoly, 1, 0.0,matOriginal1 );


// xoa con tro
     delete [] x;
     delete  line_R_L;
     delete  line_A_B_Left;//duong trai
     delete  line_A_B_Right;//duong phai

            // xử lý Warp
     float w = 640, h = 480;
      Point2f hinhthang[4] = { {-11,160}, {651,160 },{-370,480},{1010,480} };
     Point2f rec[4] = { {0.0f,0.0f}, {w,0.0f },{0.0f,h} ,{w,h} };
             Mat matrix = getPerspectiveTransform(hinhthang, rec);
             warpPerspective(over, imgWarp, matrix, Point(w, h));

             //cout << imgWarp.cols;

             int Center_1 = Xcenter_M(imgWarp);
             int Center_2 = Xcenter_M(imgWarp(Range(350, 480), Range(0, 640)));

                  int C = Center_1 - Center_2;
                  cout<< C<<endl;
                  circle(matOriginal1, Point(Center_2,470), 10, Scalar(255, 155, 255), FILLED);
                  circle(matOriginal1, Point(Center_1, 460), 10, Scalar(255, 255, 0), FILLED);

                         if (C > -15 && C < 15) {
                             putText(matOriginal1, "DI THANG ", Point(60,60), FONT_HERSHEY_SIMPLEX, 2, Scalar(255, 40, 0), 3);
                             QString cmd ="g";
                             WriteData(cmd.toUtf8());
                         }
                         else if (C<= -15 && C>= -30 ) {
                             putText(matOriginal1, " DI SANG TRAI 1", Point(60, 60), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 40, 255), 3);
                             QString cmd ="1";
                             WriteData(cmd.toUtf8());
                         }
                         else if (C<= -30 && C>= -50 ){
                             putText(matOriginal1, " DI SANG TRAI 2", Point(60, 60), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 40, 255), 3);
                             QString cmd ="2";
                             WriteData(cmd.toUtf8());
                         }
                         else if (C<= -50 && C>= -70 ){
                             putText(matOriginal1, " DI SANG TRAI 3", Point(60, 60), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 40, 255), 3);
                             QString cmd ="3";
                             WriteData(cmd.toUtf8());
                         }
                         else if (C<= -70 && C>= -90 ){
                             putText(matOriginal1, " DI SANG TRAI 4", Point(60, 60), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 40, 255), 3);
                             QString cmd ="4";
                             WriteData(cmd.toUtf8());
                         }
                         else if (C<= -90 && C>= -110 ){
                             putText(matOriginal1, " DI SANG TRAI 5", Point(60, 60), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 40, 255), 3);
                             QString cmd ="5";
                             WriteData(cmd.toUtf8());
                         }
                         else if ( C  >= 15 && C< 30) {

                             putText(matOriginal1, "DI SANG PHAI 1  ", Point(60, 60), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 40, 255), 3);
                             QString cmd ="6";
                             WriteData(cmd.toUtf8());
                         }
                        else if ( C >= 30 && C <= 50) {

                             putText(matOriginal1, "DI SANG PHAI 2 ", Point(60, 60), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 40, 255), 3);
                             QString cmd ="7";
                             WriteData(cmd.toUtf8());
                         }
                         else if ( C >= 50 && C <= 70) {

                             putText(matOriginal1, "DI SANG PHAI 3 ", Point(60, 60), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 40, 255), 3);
                             QString cmd ="8";
                             WriteData(cmd.toUtf8());
                         }
                         else if ( C >= 70 && C <= 90) {

                             putText(matOriginal1, "DI SANG PHAI 4 ", Point(60, 60), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 40, 255), 3);
                             QString cmd ="9";
                             WriteData(cmd.toUtf8());
                         }
                         else if ( C >= 90 && C <= 110) {

                             putText(matOriginal1, "DI SANG PHAI 5 ", Point(60, 60), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 40, 255), 3);
                             QString cmd ="10";
                             WriteData(cmd.toUtf8());
                         }



//

            //}
//             else {
//                 // hiện lane ra màn hình
//          QImage qimgProcessed=convertOpenCVMatToQtQImage(matOriginal1);
//          ui->imgOriginal_2->setPixmap(QPixmap::fromImage(qimgProcessed));
//                 return;}






                  // hiện lane ra màn hình
                     QImage qimgProcessed=convertOpenCVMatToQtQImage(matOriginal1);
                     ui->imgOriginal_2->setPixmap(QPixmap::fromImage(qimgProcessed));




}

void MainWindow::on_Len_pressed()
{
    QString cmd ="1";
    WriteData(cmd.toUtf8());
}

void MainWindow::on_Len_released()
{
    QString cmd ="0";
    WriteData(cmd.toUtf8());
}


// nhấn
void MainWindow::on_Sang_Phai_pressed()
{

    QString cmd ="10";
    WriteData(cmd.toUtf8());
}

// nhả
void MainWindow::on_Sang_Phai_released()
{
    QString cmd ="0";
    //WriteData(cmd.toUtf8());
}

void MainWindow::on_Sang_Trai_released()
{
    QString cmd ="0";
    //ui->textEdit->setText("nhả");
    //WriteData(cmd.toUtf8());
}


void MainWindow::on_Sang_Trai_pressed()
{

    QString cmd ="5";
    ui->textEdit->setText("nhản");
    WriteData(cmd.toUtf8());

}



void MainWindow::on_Lui_released()
{
    QString cmd ="0";
    WriteData(cmd.toUtf8());
}


void MainWindow::on_Lui_pressed()
{

    QString cmd ="2";
    WriteData(cmd.toUtf8());
}

