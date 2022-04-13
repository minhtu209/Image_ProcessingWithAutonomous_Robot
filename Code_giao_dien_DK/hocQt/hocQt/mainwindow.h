#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDial>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include "comserial.h"


using namespace cv;
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    VideoCapture capwebcam;
    Mat matOriginal1;
    Mat matOriginal;
    Mat matProcesResize;
    Mat matline;
    Mat matResize;
    QImage qimgOriginal;
    QImage qimgProcessed;

    vector<vector<int>>myColor;
   QTimer *tmrTimer;
   QTimer*Timer_Process;
   bool test;
   int Center_10 ;
   int Center_20 ;
   vector < int> lan_10;
   vector < int> lan_20;

private:


private slots:

 //.......Hàm xử lý ảnh
    void  showMat();
   void videoOriginal();

 //..............

 //......hàm liên quan đến serial
    void on_Disconnect_clicked();
    void on_Connect_clicked();
    void dst_Mat();
    void WriteData(const QByteArray data);
    void ReadData();
// .....................................

//.... hàm hiển thị ảnh lên GUI
    QImage convertOpenCVMatToQtQImage(Mat mat);
//........................

//....hàm button............
    void on_btnPauseOrResume_clicked();

    void on_Len_clicked();
//......................

    void on_Len_pressed();

    void on_Len_released();

    void on_Sang_Phai_released();

    void on_Sang_Phai_pressed();

    void on_Sang_Trai_released();

    void on_Sang_Trai_pressed();

    void on_Lui_released();

    void on_Lui_pressed();

private:
    Ui::MainWindow *ui;
    QSerialPort *devserial;
    comserial *procSerial;
};
#endif // MAINWINDOW_H
