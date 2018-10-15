#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    double x1,x2,y1,y2,x3,y3,xc,yc,r=1e9;
    vector<pair<double,double> > pts;
    int N;
    cin >> N;
    for(int i=0;i<N;i++) {
        pair<double,double> p;
        cin >> p.first >> p.second;
        pts.push_back(p);
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            for(int k=0;k<N;k++) {
                x1 = pts[i].first;
                y1 = pts[i].second;
                x2 = pts[j].first;
                y2 = pts[j].second;
                x3 = pts[k].first;
                y3 = pts[k].second;
                xc = (-2.0*(y1-y2)*(x1*x1-x3*x3+y1*y1-y3*y3)-2.0*(y3-y1)*(x1*x1-x2*x2+y1*y1-y2*y2))/(4.0*(x2*y3-x2*y1-x1*y3+y1*x3-y2*x3+y2*x1));
                yc = (x1*x1-x2*x2+xc*(2.0*x2-2.0*x1)+y1*y1-y2*y2)/(2.0*y1-2.0*y2);
                double temp = pow((xc-x1)*(xc-x1)+(yc-y1)*(yc-y1),0.5);
                bool inside = true;
                for(int m=0;m<N;m++) {
                    if((xc-pts[m].first)*(xc-pts[m].first)+(yc-pts[m].second)*(yc-pts[m].second)>temp*temp && m!=i && m!=j && m!=k) inside = false;
                }
                if(inside) r = min(r,temp);
            }
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            double dist = sqrt((pts[i].first-pts[j].first)*(pts[i].first-pts[j].first)+(pts[i].second-pts[j].second)*(pts[i].second-pts[j].second))/2.0;
            xc = (pts[i].first+pts[j].first)/2.0;
            yc = (pts[i].second+pts[j].second)/2.0;
            bool inside = true;
            for(int k=0;k<N;k++) {
                if((xc-pts[k].first)*(xc-pts[k].first)+(yc-pts[k].second)*(yc-pts[k].second)>dist*dist && k!=i && k!=j) inside = false;
            }
            if(inside) r = min(r,dist);
        }
    }
    printf("%.2f",r*2);
    return 0;
}
