#ifndef IMAGEVIEWERWINDOW_H
#define IMAGEVIEWERWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QThread>
#include "cvmatandqimage.h"
#include<opencv2/opencv.hpp>

// Definimos algunos tipos para que el código se lea mejor
typedef std::vector<cv::Mat> ImagesType;
typedef std::vector<std::vector<cv::Point> > ContoursType;


namespace Ui {
class ImageViewerWindow;
}

class Image_Thread : public QObject
{
    Q_OBJECT

    signals:
        // Señal emitida cuando el frame ha sido procesado
        void send_image(const QImage &image,const QVector<QRect> &VRect);

    public slots:
        // Método encargado del ordenamiento
        void process_image(const QImage &image);
    public:
        Image_Thread()
        {
            backgroundSubtractor = new cv::BackgroundSubtractorMOG2(500,16,false);
            backgroundSubtractor->set("nmixtures",3);
        }

private:
        cv::BackgroundSubtractorMOG2 *backgroundSubtractor;
        cv::Mat foregroundMask;
};

class ImageViewerWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ImageViewerWindow(QWidget *parent = 0);
    ~ImageViewerWindow();
signals:
    void img_ProcesorRequest(const QImage &image);

private slots:
    void on_BtSalir_clicked();

    void on_action_Salir_triggered();

    void on_action_Abrir_triggered();

    void on_movie_updated(const QRect&);

    void img_Procesed(const QImage &image,const QVector<QRect> &VRect);
private:
    QThread workingThread_;
    Image_Thread imageProcesor_;
    Ui::ImageViewerWindow *ui;
    QMovie video;
};



#endif // IMAGEVIEWERWINDOW_H
