//coin.cpp
#include "mlisp.h"

double cc(double amount, double largest__coin);
double count__change(double amount);
double next__coin(double coin);
double GR__AMOUNT();
extern double LAGEST__COIN;
extern double LAST__DIGIT__OF__GROUP__NUMBER;

double cc(double amount, double largest__coin){
{return
 (  (amount == 0 || largest__coin == 1.) ? 1.
  : !(amount  > 0 && largest__coin > 0) ? 0
  : (cc(amount, next__coin(largest__coin)) +
     cc(amount - largest__coin, largest__coin)
    )
 );
}}

double count__change(double amount){
{return
 cc(amount, LAGEST__COIN);
}}

double next__coin(double coin){
{return 
  ( coin == 50. ? 25.
  : coin == 25. ? 3.
  : coin == 3. ? 2.
  : coin == 2. ? 1.
  : 0
 );
}}

double GR__AMOUNT(){{
  return 10. * LAST__DIGIT__OF__GROUP__NUMBER;		
}}
double LAGEST__COIN=50.;
double LAST__DIGIT__OF__GROUP__NUMBER=4.;

int main(){
 display(" FB variant 2");newline();
 display(" 1-2-3 -25-50");newline();
 display("count__change for 100 \t= ");
 display(count__change(100.));newline();
 display("count__change for ");
 display(GR__AMOUNT());
 display(" \t= ");
 display(count__change(GR__AMOUNT()));newline();

 return 0;
}
