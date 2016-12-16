bool segmentsIntersect(const int&x1, const int&y1, const int&x2,const int&y2,const int&x3,const int&y3,const int&x4,const int&y4)
{
    int dx1=x2-x1;
    int dx2=y2-y1;
     
    int dy1=x3-x4;
    int dy2=y3-y4;
     
    int dz1=x3-x1;
    int dz2=y3-y1;
     
    int D=/*determinant*/ dx1*dy2-dy1*dx2;
    int E=/*determinant*/ dz1*dy2-dy1*dz2;
    int F=/*determinant*/ dx1*dz2-dz1*dx2;
     
    if(D==0) return false; //pararell
    if(D<0) { D*=-1; E*=-1; F*=-1; }
    if (E<0) return false;
    if (F<0) return false;
    if (E>D) return false;
    if (F>D) return false;
    return true;
}
