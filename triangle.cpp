#include"triangle.h"
#include<cstring>
Triangle::Triangle(){}
Triangle::Triangle(double x1,double y1,double x2,double y2,double x3,double y3)
{
    A.x=x1;
    A.y=y1;
    B.x=x2;
    B.y=y2;
    C.x=x3;
    C.y=y3;
}
char* Triangle::type() {return "Triangle";}
Point Triangle::getA() const {return A;}
Point Triangle::getB() const {return B;}
Point Triangle::getC() const {return C;}
double Triangle::AB() const {return distBetweenPoints(A,B);}
double Triangle::BC() const {return distBetweenPoints(B,C);}
double Triangle::AC() const {return distBetweenPoints(A,C);}
double Triangle::angle(char* first,char* second) const
    {
        double cosinus,a,b,c;
        if(!strcmp(first,"AB")) a=AB();
        if(!strcmp(first,"BC")) a=BC();
        if(!strcmp(first,"AC")) a=AC();
        if(!strcmp(second,"AB")) b=AB();
        if(!strcmp(second,"BC")) b=BC();
        if(!strcmp(second,"AC")) b=AC();
        if((a==AB()&&b==BC())||(b==AB()&&a==BC())) c=AC();
        if((a==AC()&&b==BC())||(b==AC()&&a==BC())) c=AB();
        if((a==AB()&&b==AC())||(b==AB()&&a==AC())) c=BC();
        cosinus=(a*a+b*b-c*c)/(2*a*b);
        return acos(cosinus);
    }
double Triangle::perim() const {return AC()+BC()+AC();}
double Triangle::area() const {return (AB()*AC()*sin(angle("AB","AC")))/2;}
double Triangle::signedArea() const {return 0.5*((B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y));}
bool Triangle::isInside(const Point& p) const     //vzeto ot StackOverflow
{
    double s=1/(2*signedArea())*(A.y*C.x-A.x*C.y+(C.y-A.y)*p.x+(A.x-C.x)*p.y);
    double t=1/(2*signedArea())*(A.x*B.y-A.y*B.x+(A.y-B.y)*p.x+(B.x-A.x)*p.y);
    return (s>0)&&(t>0)&&(s+t<1);
}
Point Triangle::centroid() const
{
    //neka G e turseniqt medicenter
    Point AC(C.x-A.x,C.y-A.y);
    Point AB(B.x-A.x,B.y-A.y);
    Point AM(0.5*AB.x+0.5*AC.x,0.5*AB.y+0.5*AC.y);
    Point AG((2.0/3.0)*AM.x,(2.0/3.0)*AM.y);
    Point G(AG.x+A.x,AG.y+A.y);
    return G;
}
Point Triangle::incenter() const
{
    //neka L e presechnata tochka na uglopolovqshtata, spusnata ot C, i AB, a I e turseniqt center na vpisanata okrujnost
    Point L=bisectorSectionPoint(A,B,C);
    Point I=bisectorSectionPoint(C,L,B);
    return I;
}
Circle Triangle::incircle() const
{
    Circle c(incenter().x,incenter().y,(2*area())/perim()); //S=pr=1/2*Pr
    return c;
}
Point Triangle::circumcenter() const
{
    //izpolzvam uravnenie ot vida y=kx+n
    //neka M e sredata na AB, a N e sredata na BC, i O e turseniqt center na opisanata okrujnost
    double k_AB,k_BC,k_OM,k_ON,n_OM,n_ON;
    Point M((A.x+B.x)/2.0,(A.y+B.y)/2.0);
    Point N((B.x+C.x)/2.0,(B.y+C.y)/2.0);
    Point O;
    k_AB=(B.y-A.y)/(B.x-A.x);
    k_BC=(C.y-B.y)/(C.x-B.x);
    if(k_AB==0||k_AB==INFINITY||k_BC==0||k_BC==INFINITY)
    {
        k_OM=-1/k_AB;
        k_ON=-1/k_BC;
        //za simetralata shte se poluchi uravnenie ot vida y=a, kudeto a e nqkakvo chislo
        if(k_AB==INFINITY) k_OM=0;
        if(k_BC==INFINITY) k_ON=0;
        //za simetralata shte se poluchi uravnenie ot vida x=a, kudeto a e nqkakvo chislo
        if(k_AB==0)
        {
            n_ON=N.y-N.x*k_ON;
            O.x=M.x;
            O.y=k_ON*O.x+n_ON;
            return O;
        }
        if(k_BC==0)
        {
            n_OM=M.y-M.x*k_OM;
            O.x=N.x;
            O.y=k_OM*O.x+n_OM;
            return O;
        }
    }
    else
    {
        k_OM=-1/k_AB;
        k_ON=-1/k_BC;
    }
    n_OM=M.y-M.x*k_OM;
    n_ON=N.y-N.x*k_ON;
    O.x=(n_ON-n_OM)/(k_OM-k_ON);
    O.y=k_OM*O.x+n_OM;
    return O;
}
Circle Triangle::circumscribedCircle() const
{
    Circle c(circumcenter().x,circumcenter().y,distBetweenPoints(circumcenter(),A));
    return c;
}
void Triangle::translation(const Point& p)
{
    A.x+=p.x;
    A.y+=p.y;
    B.x+=p.x;
    B.y+=p.y;
    C.x+=p.x;
    C.y+=p.y;
}
void Triangle::rotationAroundCenter()
{
    A.x=-A.x;
    A.y=-A.y;
    B.x=-B.x;
    B.y=-B.y;
    C.x=-C.x;
    C.y=-C.y;
}
/*istream& operator>>(istream& is,Triangle& t)
{
    is>>t.A;
    is>>t.B;
    is>>t.C;
    return is;
}
ostream& operator<<(ostream& os,const Triangle& t)
{
    os<<t.A<<endl<<t.B<<endl<<t.C<<endl;
    return os;
}*/
