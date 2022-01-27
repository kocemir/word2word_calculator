            #include "mainwindow.h"
            #include "ui_mainwindow.h"
            #include <QTextStream>
            #include <QVector>
            #include <QMessageBox>

/*
@author: Emirhan Koç
@date: 24.01.2022
@Instutition: Bilkent University, Electrical and Electronics Engineering Department



*/
            MainWindow::MainWindow(QWidget *parent)
                : QMainWindow(parent)
                , ui(new Ui::MainWindow)
            {
                ui->setupUi(this);
                ui->radioButton->setChecked(true);

                ui->uyari->setText("Dikkat! Lütfen, sadece alfabetik karakterler giriniz.");

            }


            MainWindow::~MainWindow()
            {
                delete ui;


            }

            // Write results in the form of word
            void MainWindow::WriteResult(QString res){
                QString str = res;
                ui->res->setText(str);
              //  result = " ";
                word1.clear();
                word2.clear();
            }


            // Write results in the form of in

            void MainWindow::WriteResultD(double res){
                int str = res;
                if (res<0){
                ui->res->setText(QString::number(str));
                }
                else{
                     ui->res->setText(QString::number(str));
                }
                 total = 0;
            }


             // Store given word numbers using vectors
            void MainWindow::getNumbers(){

                number1= ui->num1->text();
                number2= ui->num2->text();



                // Store string word by word using QTextStream( stringstream in C++)
                QString w1,w2;
                QTextStream stream1(&number1);
                QTextStream stream2(&number2);

                while(!stream1.atEnd()) {

                    stream1 >> w1;
                    word1.append(w1);

                }

                while(!stream2.atEnd()) {

                    stream2 >> w2;
                    word2.append(w2);

                }


            }


           int MainWindow::TenFind(QVector<QString> yuz_arr,QVector<QString> birler, QVector<QString> onlar){



               int sum_All =0;


               int myflag = 0;
               QString temp = " ";
               foreach(QString str,onlar){

                   if(yuz_arr.contains(str)){

                       myflag= 1;
                       temp = str;
                   }
               }


               if(myflag==0){

                   sum_All = birler.indexOf(yuz_arr.at(0));
               }


               else
               {

                       if(yuz_arr.size()==1){
                           sum_All=(onlar.indexOf(temp)+1)*10;
                       }
                      if(yuz_arr.size()==2){
                          sum_All =( onlar.indexOf(temp)+1)*10+ birler.indexOf(yuz_arr.at(1));
                      }

                 }

               return sum_All;



           }



        int MainWindow::HundredFind(QVector<QString> yuz_arr){



            QVector<QString> birler;
            birler << "zero" <<"one"<<"two"<<"three"<<"four"<<"five"<<"six"<<"seven"<<"eight"<<"nine"<<"ten"<< "eleven"<<"twelve"<< "thirteen"<< "fourteen"<<"fifteen"<<"sixteen"<<"seventeen"<<"eighteen"<<"nineteen";

            QVector<QString> onlar;
            onlar << " "<< "twenty"<<"thirty"<<"fourty"<<"fifty"<<"sixty"<<"seventy"<<"eighty"<<"ninety";


            int sum_All = 0;

            bool checker = yuz_arr.contains("hundred");


            if (checker ==false){


             sum_All = TenFind(yuz_arr,birler,onlar);



            }


            else{

               int ind_yuz = yuz_arr.indexOf("hundred");



               int length_yuz = yuz_arr.length();





              if (length_yuz-1 == ind_yuz){

                  if( ind_yuz ==0){
                      sum_All= 100;

                  }

                  else{

                     int bbb= birler.indexOf(yuz_arr.at(0));

                     sum_All= bbb*100;

                  }


              }




              else{


               QVector<QString> parsed;
               parsed = yuz_arr.mid(ind_yuz+1,-1);

               int sum_after_yuz = OnBul(parsed,birler,onlar);

               if( ind_yuz ==0){
                   sum_All= sum_after_yuz+100*1;

               }
               else{

                  int bb= birler.indexOf(yuz_arr.at(0));

                  sum_All= sum_after_yuz+ bb*100;

               }



            }
          }
          return sum_All;





        }


      int MainWindow::ThousandFind(QVector<QString> bin_arr)
        {

          int sum_All = 0;

          QVector<QString> birler;
          birler << "zero" <<"one"<<"two"<<"three"<<"four"<<"five"<<"six"<<"seven"<<"eight"<<"nine";

          QVector<QString> onlar;
          onlar << "ten"<<"twenty"<<"thirty"<<"fourty"<<"fifty"<<"sixty"<<"seventy"<<"eighty"<<"ninety";



          bool checker = bin_arr.contains("thousand");


          if( checker == false){

              sum_All = HundredFind(bin_arr);

          }


          else {

               int ind_bin = bin_arr.indexOf("thousand");

               int length_bin = bin_arr.length();





              if (length_bin-1 == ind_bin){

                  if( ind_bin ==0){
                      sum_All= 1000;

                  }

                  else{


                     QVector<QString> pars_bin = bin_arr.mid(0,ind_bin);
                     int yy = HundredFind(pars_bin);

                     sum_All= yy*1000;

                  }


              }




              else{

                  if (ind_bin ==0){


                      QVector<QString> pars_aft= bin_arr.mid(ind_bin+1,-1);
                      int aft = HundredFind(pars_aft);

                      sum_All = 1000+aft;

                  }
                  else{
                   QVector<QString> pars_prev= bin_arr.mid(0,ind_bin);
                   int pre = HundredFind(pars_prev)*1000;

                   QVector<QString> pars_after= bin_arr.mid(ind_bin+1,-1);
                   int after = HundredFind(pars_after);
                   sum_All= pre+after;
                  }



              }


          }


          return sum_All;






        }















            int MainWindow::OnBul(QVector<QString> yuz_arr,QVector<QString> birler, QVector<QString> onlar){

                int sum_All =0;


                int myflag = 0;
                QString temp = " ";
                foreach(QString str,onlar){

                    if(yuz_arr.contains(str)){

                        myflag= 1;
                        temp = str;
                    }
                }


                if(myflag==0){

                    sum_All = birler.indexOf(yuz_arr.at(0));
                }


                else
                {

                        if(yuz_arr.size()==1){
                            sum_All=(onlar.indexOf(temp)+1)*10;
                        }
                       if(yuz_arr.size()==2){
                           sum_All =( onlar.indexOf(temp)+1)*10+ birler.indexOf(yuz_arr.at(1));
                       }

                  }

                return sum_All;



            }






            int MainWindow::YuzBul(QVector<QString> yuz_arr){



                QVector<QString> birler;
                birler << "sıfır" <<"bir"<<"iki"<<"üç"<<"dört"<<"beş"<<"altı"<<"yedi"<<"sekiz"<<"dokuz";

                QVector<QString> onlar;
                onlar << "on"<<"yirmi"<<"otuz"<<"kırk"<<"elli"<<"altmış"<<"yetmiş"<<"seksen"<<"doksan";


                int sum_All = 0;

                bool checker = yuz_arr.contains("yüz");


                if (checker ==false){


                 sum_All = OnBul(yuz_arr,birler,onlar);



                }


                else{

                   int ind_yuz = yuz_arr.indexOf("yüz");



                   int length_yuz = yuz_arr.length();





                  if (length_yuz-1 == ind_yuz){

                      if( ind_yuz ==0){
                          sum_All= 100;

                      }

                      else{

                         int bbb= birler.indexOf(yuz_arr.at(0));

                         sum_All= bbb*100;

                      }


                  }




                  else{


                   QVector<QString> parsed;
                   parsed = yuz_arr.mid(ind_yuz+1,-1);

                   int sum_after_yuz = OnBul(parsed,birler,onlar);

                   if( ind_yuz ==0){
                       sum_All= sum_after_yuz+100*1;

                   }
                   else{

                      int bb= birler.indexOf(yuz_arr.at(0));

                      sum_All= sum_after_yuz+ bb*100;

                   }



                }
              }
              return sum_All;

            }




          int MainWindow::BinBul(QVector<QString> bin_arr){
              int sum_All = 0;

              QVector<QString> birler;
              birler << "sıfır" <<"bir"<<"iki"<<"üç"<<"dört"<<"beş"<<"altı"<<"yedi"<<"sekiz"<<"dokuz";

              QVector<QString> onlar;
              onlar << "on"<<"yirmi"<<"otuz"<<"kırk"<<"elli"<<"altmış"<<"yetmiş"<<"seksen"<<"doksan";


              bool checker = bin_arr.contains("bin");

              if( checker == false){

                  sum_All = YuzBul(bin_arr);

              }


              else {

                   int ind_bin = bin_arr.indexOf("bin");

                   int length_bin = bin_arr.length();





                  if (length_bin-1 == ind_bin){

                      if( ind_bin ==0){
                          sum_All= 1000;

                      }

                      else{


                         QVector<QString> pars_bin = bin_arr.mid(0,ind_bin);
                         int yy = YuzBul(pars_bin);

                         sum_All= yy*1000;

                      }


                  }




                  else{

                      if (ind_bin ==0){


                          QVector<QString> pars_aft= bin_arr.mid(ind_bin+1,-1);
                          int aft = YuzBul(pars_aft);

                          sum_All = 1000+aft;

                      }
                      else{
                       QVector<QString> pars_prev= bin_arr.mid(0,ind_bin);
                       int pre = YuzBul(pars_prev)*1000;

                       QVector<QString> pars_after= bin_arr.mid(ind_bin+1,-1);
                       int after = YuzBul(pars_after);
                       sum_All= pre+after;
                      }



                  }


              }


              return sum_All;

          }

          int MainWindow::Eksi(QVector<QString> array_bin){

              int sum_All=0;

              if(array_bin.contains("eksi")){
                  sum_All= -1*BinBul(array_bin.mid(1,-1));
              }
              else{

                  sum_All= BinBul(array_bin);
              }

              return sum_All;
          }

         int MainWindow::Minus(QVector<QString> array_bin)

         {

             int sum_All=0;

             if(array_bin.contains("minus")){
                 sum_All= -1*ThousandFind(array_bin.mid(1,-1));
             }
             else{

                 sum_All= ThousandFind(array_bin);
             }

             return sum_All;

         }






            void MainWindow::Converter(){

                QVector<QString> birler;
                birler << "sıfır" <<"bir"<<"iki"<<"üç"<<"dört"<<"beş"<<"altı"<<"yedi"<<"sekiz"<<"dokuz";

                QVector<QString> onlar;
                onlar << "on"<<"yirmi"<<"otuz"<<"kırk"<<"elli"<<"altmış"<<"yetmiş"<<"seksen"<<"doksan";



              //  sayi1 = OnBul(word1,birler,onlar);
              //  sayi2 = OnBul(word2,birler,onlar);

                if (lang_turkish)
                {
                sayi1 = Eksi(word1);
                sayi2=  Eksi(word2);
                }

                else{
                sayi1= Minus(word1);
                sayi2= Minus(word2);

                 }




     }





       QString MainWindow::Num2Word(int num,QString word){

          QString str = "";



          if ( num > 19 && num <100){

              str += onlar[num/10]+ " " + birler[num%10];
          }
          else if(num<20) {
              str=str+ birler[num];
          }

          else{

              int num_modified = num%100-num%10;
              if( num_modified >19){
              str+=  yuzler[num/100]+ " "+ onlar[num_modified/10]+" " +birler[num%10];
              }
              else{
                  str+= yuzler[num/100]+ " " + birler[num%100];
              }

          }

          if(num){
              str = str + " "+  word;
          }


         return str;
       }



        void MainWindow::ConvertMeBackBabe(){



            QString res = " ";
            int temp_total= total;



            if (total==0){

                res = "sıfır";
            }



            else{



             if (total >0){



            int milya=temp_total/1000000000;
            res+= Num2Word(milya," milyar ");
            temp_total=temp_total-milya*1000000000;

            int milyo= temp_total/1000000;

            res+= Num2Word(milyo," milyon ");
            temp_total = temp_total-milyo*1000000;

            int bbin = temp_total/1000;
            if(bbin==1){
                res+=" bin ";
            }

            else{
            res+= Num2Word(bbin," bin ");
            }

            temp_total=temp_total-bbin*1000;

            res= res+ Num2Word(temp_total," ");

             }

             else
             {

                 temp_total= total*(-1);

                 int milya=temp_total/1000000000;
                 res+= Num2Word(milya," milyar ");
                 temp_total=temp_total-milya*1000000000;

                 int milyo= temp_total/1000000;

                 res+= Num2Word(milyo," milyon ");
                 temp_total = temp_total-milyo*1000000;

                 int bbin = temp_total/1000;
                 if(bbin==1){
                     res+=" bin ";
                 }

                 else{
                 res+= Num2Word(bbin," bin ");
                 }

                 temp_total=temp_total-bbin*1000;

                 res= res+ Num2Word(temp_total," ");
                 res = "eksi" + res;
                  }


             }


               result= res;






        }






        QString MainWindow::Num2Word_English(int num, QString word){



            QString birs [20] =  {"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen", "eighteen", "nineteen"
                                 };
            QString yuzs[10] = {"", "one hundred","two hundred","three hundred","four hundred","five hundred","six hundred","seven hundred","eight hundred","nine hundred"};

            QString ons [10] = {"","", "twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};




            QString str = " ";



            if ( num > 19 && num <100){

                str += ons[num/10]+ " " + birs[num%10];
            }
            else if(num<20) {
                str=str+ birs[num];
            }

            else{

                int num_modified = num%100-num%10;
                if( num_modified >19){
                str+=  yuzs[num/100]+ " "+ ons[num_modified/10]+" " +birs[num%10];
                }
                else{
                    str+= yuzs[num/100]+ " " + birs[num%100];
                }

            }

            if(num){
                str = str + " "+  word;
            }


           return str;





        }



        void MainWindow::ConvertMeBackBabe_English(){



            QString res = " ";
            int temp_total= total;



            if (total==0)
            {

                res = "zero";
            }


            else{



            if (total >0){



            int milya=temp_total/1000000000;
            res+= Num2Word_English(milya," billion ");
            temp_total=temp_total-milya*1000000000;

            int milyo= temp_total/1000000;

            res+= Num2Word_English(milyo," million ");
            temp_total = temp_total-milyo*1000000;

            int bbin = temp_total/1000;



            res+= Num2Word_English(bbin," thousand ");


            temp_total=temp_total-bbin*1000;

            res= res+ Num2Word_English(temp_total," ");

             }

             else
             {

                 temp_total= total*(-1);

                 int milya=temp_total/1000000000;
                 res+= Num2Word_English(milya," billion ");
                 temp_total=temp_total-milya*1000000000;

                 int milyo= temp_total/1000000;

                 res+= Num2Word_English(milyo," million ");
                 temp_total = temp_total-milyo*1000000;

                 int bbin = temp_total/1000;




                 res+= Num2Word_English(bbin," thousand ");


                 temp_total=temp_total-bbin*1000;

                 res= res+ Num2Word_English(temp_total," ");
                 res = "minus" + res;
                  }


             }


               result= res;




        }





            void MainWindow::on_plus_button_clicked()


            {
                 getNumbers();
                 Converter();
                total = sayi1+sayi2;
                if(lang_turkish==false){
                ConvertMeBackBabe_English();
                }
                else{
                      ConvertMeBackBabe();
                }

               WriteResult(result);


            }
            void MainWindow::on_substract_button_clicked()
            {
                getNumbers();
                Converter();
                total = sayi1-sayi2;
                if(lang_turkish==false){
                ConvertMeBackBabe_English();
                }
                else{
                      ConvertMeBackBabe();
                }

               WriteResult(result);


            }

            void MainWindow::on_division_button_clicked()

            {

                getNumbers();
                Converter();

               if (sayi2==0&& lang_turkish){
                   QMessageBox messageBox;
                   messageBox.critical(0,"Hatalı işlem.", "Sıfır ile bölme işlemi yapamazsınız.");
               }

               if (sayi2==0&& lang_turkish==false){
                   QMessageBox messageBox1;
                   messageBox1.critical(0,"Wrong operation!", "Division by zero is invalid operation");
               }


                total = sayi1/sayi2;
                if(lang_turkish==false){
                ConvertMeBackBabe_English();
                }
                else{
                      ConvertMeBackBabe();
                }

                WriteResult(result);







            }

            void MainWindow::on_multiplication_button_clicked()
            {        getNumbers();
                     Converter();
                     total = sayi1*sayi2;
                     if(lang_turkish==false)
                      {
                          ConvertMeBackBabe_English();
                          }
                      else{
                                ConvertMeBackBabe();
                          }

                      WriteResult(result);

            }








void MainWindow::on_radioButton_clicked()
{



    ui->label->setText("Sayı "+ QString::number(1));
    ui->label_2->setText("Sayı "+ QString::number(2));
    ui->label_3->setText("Sonuç");
    ui->label_4->setText("İlginç Hesap Makinesi");


    ui->uyari->setText("Dikkat! Lütfen, sadece alfabetik karakterler giriniz.");
    ui->plus_button->setText("Topla");
    ui->substract_button->setText("Çıkar");
    ui->division_button->setText("Böl");
    ui->multiplication_button->setText("Çarp");

    /*

    int total_temp= total;

    total=sayi1;
    ConvertMeBackBabe();
    ui->num1->setText(result);
    total=sayi2;
    ConvertMeBackBabe();
    ui->num2->setText(result);
    total=total_temp;
    ConvertMeBackBabe();
    WriteResult(result);



    */

    lang_turkish = true;



}


void MainWindow::on_radioButton_2_clicked()
{


      ui->label->setText("Value "+ QString::number(1));
      ui->label_2->setText("Value "+ QString::number(2));
      ui->label_3->setText("Result");
      ui->label_4->setText("Weird Calculator");

      ui->uyari->setText("Attention! Please,enter only alphabethic characters.");

      ui->plus_button->setText("Sum");
      ui->substract_button->setText("Substract");
      ui->division_button->setText("Divide");
      ui->multiplication_button->setText("Multiply");

/*
      int total_temp= total;

      total=sayi1;
      ConvertMeBackBabe_English();
      ui->num1->setText(result);
      total=sayi2;
      ConvertMeBackBabe_English();
      ui->num2->setText(result);
      total=total_temp;
      ConvertMeBackBabe_English();
      WriteResult(result);


*/
      lang_turkish = false;

}


