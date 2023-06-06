#include "dialogclient2.h"
#include "ui_dialogclient2.h"
#include "QFile"
#include "vector"
#include "map"
#include "iostream"
#include "string"

DialogClient2::DialogClient2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogClient2)
{
    ui->setupUi(this);
    ui->label->setHidden(1);
    ui->label_2->setHidden(1);
    ui->label_3->setHidden(1);
    ui->label_4->setHidden(1);

}

DialogClient2::~DialogClient2()
{
    delete ui;
}

void splitString(std::string inputString, std::string delimiter, std::vector<std::string>& array1, std::vector<std::string>& array2, std::vector<std::string>& array3) {
    size_t pos = 0;
    std::string token;
    int index = 0;
    while ((pos = inputString.find(delimiter)) != std::string::npos) {
        token = inputString.substr(0, pos);
        switch (index % 3) {
        case 0:
            array1.push_back(token);
            break;
        case 1:
            array2.push_back(token);
            break;
        case 2:
            array3.push_back(token);
            break;
        }
        inputString.erase(0, pos + delimiter.length());
        index++;
    }
    switch (index % 3) {
    case 0:
        array1.push_back(inputString);
        break;
    case 1:
        array2.push_back(inputString);
        break;
    case 2:
        array3.push_back(inputString);
        break;
    }
}


void DialogClient2::on_pushButton_clicked()
{
    ui->label->setHidden(0);
    ui->label_2->setHidden(0);
    ui->label_3->setHidden(0);
    ui->label_4->setHidden(0);
            QString qs = ("/Users/gaaroo/TestQT/Clients/" + ui->lineEdit->text() + ".txt");
            QFile file(qs);

            std::string delimiter = "/0";

            size_t pos = 0;
            std::string token;
                    if (file.exists()) {
                            file.open(QIODevice::ReadOnly);
                                std::string mystring;
                            mystring = file.readAll();
                                std::string favDay, favDish, favTime;
                                int averageMoney, size = 1;
                                std::vector <std::string> daysArray, dishesArray, timeArray;


                                splitString(mystring, "/0", daysArray, dishesArray, timeArray) ;


                                {
                                std::map<std::string, int> counts;
                                for (std::string s : daysArray) {
            counts[s]++;
                                }

                                int max_count = 0;
                                std::string days_most_frequent = "";
                                for (auto& pair : counts) {
            if (pair.second > max_count) {
                max_count = pair.second;
                days_most_frequent = pair.first;
                ui->label->setText(QString::fromStdString(days_most_frequent));
            }
                                }
                                }
                                {
                                std::map<std::string, int> countss;
                                for (std::string ss : dishesArray) {
            countss[ss]++;
                                }

                                int max_countt = 0;
                                std::string dishes_most_frequent = "";
                                for (auto& pair : countss) {
            if (pair.second > max_countt) {
                max_countt = pair.second;
                dishes_most_frequent = pair.first;
                ui->label_3->setText(QString::fromStdString(dishes_most_frequent));
            }
                                }
                                }
                                {
                                std::map<std::string, int> countsss;
                                for (std::string sss : timeArray) {
            countsss[sss]++;
                                }
                                file.close();

                                int max_counttt = 0;
                                std::string time_most_frequent = "";
                                for (auto& pair : countsss) {
            if (pair.second > max_counttt) {
                max_counttt = pair.second;
                time_most_frequent = pair.first;
                    ui->label_2->setText(QString::fromStdString(time_most_frequent));
            }
                                }
                                }
                                int amount;
                                std::string newString;
                                amount = std::size(timeArray);
                                int total = 0;

                                for (int zis = 0; zis < amount; zis++) {
                                QString qs = ("/Users/gaaroo/TestQT/DishBase/" + QString::fromStdString(timeArray[zis]) + ".txt");
                                QFile file(qs);
                                if (file.exists()) {
                                file.open(QIODevice::ReadOnly);
            newString = file.readAll();
                                total = std::stoi(newString);
                                   file.close();
                                }

}

                                newString = std::to_string(total/amount);
                                ui->label_4->setText(QString::fromStdString(newString));

}

}

void DialogClient2::on_pushButton_2_clicked()
{
close();
}

