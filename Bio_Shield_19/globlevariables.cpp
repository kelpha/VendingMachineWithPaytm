#include "globlevariables.h"

bool TestApp;
int dispence_Count;
int dis_count;

int Unit_price;
int stock_1;
int stock_2;
int stock_3;
int stock_4;
QString Paytm_link_1;
QString Paytm_link_2;
QString Serial_no;
GlobleVariables::GlobleVariables()
{

}

void GlobleVariables::InitVariable()
{
   TestApp=false;
   dispence_Count=0;
   dis_count=1;

   Unit_price=10;
   stock_1=0;
   stock_2=0;
   stock_3=0;
   stock_4=0;
   Paytm_link_1="not configured";
   Paytm_link_2="not configured";
   Serial_no="";
}
