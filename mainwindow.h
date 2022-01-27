#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QVector>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString number1=" ", number2=" ",result=" ";
    int sayi1=0, sayi2=0, total = 0;

    QVector<QString> word1;
    QVector<QString> word2;




    QString birler [20] =  {"","bir","iki","üç","dört","beş","altı","yedi","sekiz","dokuz","on","on bir","on iki","on üç","on dört","on beş",

                         "on altı","on yedi", "on sekiz", "on dokuz"
                         };
    QString yuzler[10] = {"", "yüz","iki yüz","üç yüz","dört yüz","beş yüz","altı yüz","yedi yüz","sekiz yüz","dokuz yüz"};

    QString onlar [10] = {"","", "yirmi","otuz","kırk","elli","altmış","yetmiş","seksen","doksan"};

    bool lang_turkish = true;


    void getNumbers();
    void WriteResult(QString res);
    void Converter();
    void ConvertBack();
    int YuzBul(QVector<QString> yuz_array);
    int OnBul(QVector<QString> yuz_array,QVector<QString> birs, QVector<QString> ons);
    int BinBul(QVector<QString> bin);
    void ConvertMeBackBabe();
    QString Num2Word(int num, QString str);
    int Eksi(QVector<QString> array_bin);
    void WriteResultD(double res);





    // English


   int  TenFind(QVector<QString> hundred_arr,QVector<QString> ones, QVector<QString> tens);
   int HundredFind(QVector<QString> yuz_arr);
   int ThousandFind(QVector<QString> bin_arr);
   QString Num2Word_English(int num,QString str);
   void ConvertMeBackBabe_English();
   int Minus(QVector<QString> array_bin);
public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_plus_button_clicked();


    void on_substract_button_clicked();

    void on_division_button_clicked();

    void on_multiplication_button_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();




private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
