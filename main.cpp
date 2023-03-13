    #include <iostream>
    #include <stdlib.h>
    #include <string.h>
    #include <vector>

    using namespace std;

    struct acento {
        char colum;
        int linha;
    };

    struct user{
        string name;
        string mail;
    };

    struct Time{
        int h;
        int m;
    };

    struct Ticket {
        int id;
        string depCity;
        string arrCity;
        Time depTime;
        string classBus;
        int TrvlHours;

    };


    //funções para retornar a hora em um formato HH:mm
    /*string DeptimeToString(){
        Ticket ticket;
        return ticket.depTime.h + ":" + ticket.depTime.m;
    };

    string arrtimeToString(int i){
        Ticket ticket;
        return ticket[i].arrTime.h + ":" + ticket.arrTime.m;
    }*/



    int main() {
        int qnt_ticket = 0;
        user user;
        Ticket ticket[20];
        Ticket buiedTicket[20];
        cout << "Login"<<endl;
        cout << "first, write your name and Mail " << endl;
        cout << "nome:";
        cin >> user.name;
        cout << "mail:";
        cin >> user.mail;


        cout << endl;
        cout << endl;

        cout << "hello " + user.name + ", wellcome to our buy ticket sistem of bus " << endl;

        while (true) {
            cout << "what want do you do?";
            cout << endl;
            cout << endl;
            cout << "[1] - see available tickets" << endl;
            cout << "[2] - create a ticket" << endl;
            cout << "[3] - buy a ticket" << endl;
            cout << "[4] - exit" << endl;

            cout << endl;
            cout << "response:";
            char choose[10];// tipo char para usar na função (strcmp)
            cin >> choose;

            //declaração para poder usar strcmp, onde só aceita variaveis constantes
            char see[2] = "1";
            char create[2] = "2";
            char buy[2] = "3";
            char exit[2] = "4";

            if (!strcmp(choose, see) || !strcmp(choose, create) || !strcmp(choose, buy) || !strcmp(choose, exit)){

                //criar ticket
                if(!strcmp(choose, create)){
                    int id;
                    string depCity;
                    string arrCity;
                    string nameBus;
                    int hour;
                    int minutes;
                    int chooseBus;
                    string ClassBuss;
                    int trvlHours;
                    bool validation = true;


                    cout << "to register, enter the datas: " << endl;

                    if (qnt_ticket > 0){
                        while (validation == true){  //validar se o id ja existe ou não
                            cout << "id:";
                            cin >> id;

                            for (int i = 0; i < qnt_ticket ; i++){
                                if (id == ticket[i].id){
                                    cout << "This is id not available, try again" << endl;
                                }
                                else {
                                    validation = false;
                                }
                            }
                        }
                    }

                    else{
                        cout << "id:";
                        cin >> id;
                    }
                    cout << "Departure city:";
                    cin >> depCity;
                    cout << "Arrival city:";
                    cin >> arrCity;
                    cout << "departure time:" << endl;
                    cout << "hour(hh):";
                    cin >> hour;
                    cout << "minutes(mm):";
                    cin >> minutes;
                    cout << "Travel Hours:";
                    cin >> trvlHours;
                    cout << "class Bus:" << endl;
                    cout << "[1] = economic" << endl;
                    cout << "[2] = premium" << endl;
                    cout << "[3] = executive" << endl;
                    cin >> chooseBus;

                    switch (chooseBus) {
                        case 1:
                            ClassBuss = "Economic";
                        case 2:
                            ClassBuss = "Premium";
                        case 3:
                            ClassBuss = "Executive";

                    }


                    ticket[qnt_ticket].id = id;
                    ticket[qnt_ticket].depCity = depCity;
                    ticket[qnt_ticket].arrCity = arrCity;
                    ticket[qnt_ticket].depTime.h = hour;
                    ticket[qnt_ticket].depTime.m = minutes;
                    ticket[qnt_ticket].classBus = ClassBuss;
                    ticket[qnt_ticket].TrvlHours = trvlHours ;
                    qnt_ticket +=1;

                //visualizar tickets
                }else if (!strcmp(choose, see)){          //com "!" pois a função retorna 1 se for diferente
                   if(qnt_ticket > 0){

                       for(int i = 0; i < qnt_ticket ; i++){

                        cout << "------------------------------------";
                        cout << endl;
                        cout << "id: " << ticket[i].id << endl;
                        cout << ticket[i].depCity << " ----> " << ticket[i].arrCity<< endl;
                        cout << ticket[i].depTime.h << ":" << ticket[i].depTime.m << "h" << endl;
                        cout << "class: " << ticket[i].classBus << endl;
                        cout << "Travel duration: " << ticket[i].TrvlHours << "h";
                        cout << endl;
                        cout << "------------------------------------" << endl;
                       }

                   }
                   else{
                       cout << "we don't have tickets registered yet";
                       cout << endl;
                       cout << endl;
                   }
               }

               //comprar tickets
               else if (!strcmp(choose, buy)){
                   int choosebuy;

                   cout << "write the id Ticket do you want buy?";
                   cin >> choosebuy;

                   for(int i = 0; i < qnt_ticket; i++){
                       if (ticket[i].id == choosebuy){
                           for(int j = i+1; j < qnt_ticket; j++){

                               ticket[i].id = ticket[j].id ;
                               ticket[i].depCity = ticket[j].depCity;
                               ticket[i].arrCity = ticket[j].arrCity;
                               ticket[i].depTime.h = ticket[j].depTime.h;
                               ticket[i].depTime.m = ticket[j].depTime.m;
                               ticket[i].classBus = ticket[j].classBus;
                               ticket[i].TrvlHours =  ticket[j].TrvlHours;
                               i++;


                           }


                       }


                   }

                   qnt_ticket--;

               }


            }else{

                cout << endl;
                cout << "we don't that option, let's try again" << endl;



            }

            cout << "------------------------------------" << endl;
        }

}

