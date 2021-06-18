#ifndef GLOBLEVARIABLES_H
#define GLOBLEVARIABLES_H

#include<QString>


extern bool TestApp;
extern int dispence_Count;
extern int dis_count;

extern int Unit_price;
extern int stock_1;
extern int stock_2;
extern int stock_3;
extern int stock_4;
extern QString Paytm_link_1;
extern QString Paytm_link_2;
extern QString Serial_no;

class GlobleVariables
{
public:
    GlobleVariables();
    void InitVariable();
};

#endif // GLOBLEVARIABLES_H
