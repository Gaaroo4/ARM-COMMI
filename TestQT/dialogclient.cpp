#include "dialogclient.h"
#include "ui_dialogclient.h"
#include <QFile>
#include <QString>
#include <map>
#include <iostream>



DialogClient::DialogClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogClient)
{


    ui->setupUi(this);
}

DialogClient::~DialogClient()
{
    delete ui;
}


void DialogClient::on_pushButton_clicked()
{
//        ui->clientName->text();
//        QString qs = ("/Users/gaaroo/TestQT/Clients/" + ui->clientName->text() + ".txt");
//        QFile file(qs);

//        std::string delimiter = "/0";

//        size_t pos = 0;
//        std::string token;
//        if (file.exists()) {
//                file.open(QIODevice::ReadOnly);
//                    std::string mystring;
//                mystring = file.readAll();
//                    std::string favDay, favDish;
//                    int favTime, averageMoney, size = 1;
//                        std::string daysArray[size], dishesArray[size], timeArray[size];
//                    for (int i = 0; i >= 3; i++) {
//                            switch (i) {
//                        case 0: {

//                                while ((pos = mystring.find(delimiter)) != std::string::npos) {
//                                    token = mystring.substr(0, pos);
//                                    daysArray[i].append(token);
//                                    mystring.erase(0, pos + delimiter.length());
//                                    break;
//                                }
//                        }

//                                case 1: {

//                                    while ((pos = mystring.find(delimiter)) != std::string::npos) {
//                                        token = mystring.substr(0, pos);
//                                        timeArray[i].append(token);
//                                        mystring.erase(0, pos + delimiter.length());
//                                        break;
//                                    }
//                                }

//                                case 2: {

//                                        while ((pos = mystring.find(delimiter)) != std::string::npos) {
//                                            token = mystring.substr(0, pos);
//                                            dishesArray[i].append(token);
//                                            mystring.erase(0, pos + delimiter.length());
//                                            break;
//                                        }
//                             }
//                                }

//                        }

//        } else {

//        }
//    typedef std::map<int, std::string> Mymap;
//    ui->clientName->text();
//    QString qs = ("/Users/gaaroo/TestQT/Clients/" + ui->clientName->text() + ".txt");
//    QFile file(qs);

//    std::string delimiter = "/0";

//    size_t pos = 0;
//    std::string token;
//    while ((pos = s.find(delimiter)) != std::string::npos) {
//        token = s.substr(0, pos);
//        std::cout << token << std::endl;
//        s.erase(0, pos + delimiter.length());
//    }
//    std::cout << s << std::endl;
//    if (file.exists()) {
//    file.open(QIODevice::ReadOnly);
//        std::string mystring;
//    mystring = file.readAll();
//        std::string favDay, favDish;
//    Mymap dayss;
//        dayss.insert(Mymap::value_type(0,"!"));
//    int favTime, averageMoney, size = 1;
//        std::string daysArray[size], dishesArray[size], timeArray[size];
//    for (int i = 0; i>=3; i++) {
//        if (mystring != "") {

//            switch (i) {
//            case 0:
//                while ((pos = mystring.find(delimiter)) != std::string::npos) {
//                            token = mystring.substr(0, pos);
//                    daysArray[size].append(token);
//                            mystring.erase(0, pos + delimiter.length());
//                        }
//                break;

//            case 1:
//                while ((pos = mystring.find(delimiter)) != std::string::npos) {
//                            token = mystring.substr(0, pos);
//                            timeArray[size].append(token);
//                            mystring.erase(0, pos + delimiter.length());
//                }
//                break;

//            case 2:
//                while ((pos = mystring.find(delimiter)) != std::string::npos) {
//                            token = mystring.substr(0, pos);
//                            dishesArray[size].append(token);
//                            mystring.erase(0, pos + delimiter.length());
//                }
//                i=0;
//                size++;
//                break;

//            }
//        } else {
//            i=3;
//        }
//    }
//    int couts = 0;
//    for (int c = 0; c!=size; c++) {
//        for (int cii = 0; cii!=size; cii++) {
//            if (daysArray[c] == daysArray[cii]) {
//                couts++;
//                favDay = daysArray[c];
//            }
//        }
//        dayss.insert(Mymap::value_type(couts, favDay));
//        couts = 0;
//    }
//    int temp = 0;
//    for (int i = 0; i!=dayss.max_size(); i++) {
//        if (dayss.at(i) == ""){
//            i = dayss.max_size();
//        } else {
//            temp = i;
//        }
//    }
//    favDay = dayss.at(temp);
//    QString dday = QString::fromStdString (favDay);
//    ui->label_3->setText(dday);
//    } else {
//    ui->label_5->setText("Такого посетителя не существует");
//    }
 }

