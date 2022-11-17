class Solution {
public:
  //if there is a common space between 2 rect. subtract it
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int tot=(abs(ax1-ax2)*abs(ay1-ay2))+
          (abs(bx1-bx2)*abs(by1-by2));
      int nx1=max(ax1,bx1);
      int ny1=max(ay1,by1);
      int nx2=min(ax2,bx2);
      int ny2=min(ay2,by2);
      int ca=(nx2-nx1)*(ny2-ny1);
      if(nx2<=nx1||ny2<ny1)
        ca=0;
      return (tot-ca);
    }
};