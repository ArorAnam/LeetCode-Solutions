#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define qq 330
using namespace std;
int vis1 [qq] [qq];//Both mark the path and count the steps
int vis2 [qq] [qq];
int fx1 [8] = {2,2, -2, -2,1,1, -1, -1};
int fx2 [8] = {1, -1,1, -1,2, -2,2, -2};
struct node {
 int x, y;
} start, end;//Both ends of bidirectional BFS      
int sx, sy, ex, ey;
int m;
bool inside (int xx, int yy)//Judge out of bounds
{
    if (xx> = 0 && yy> = 0 && xx <m && yy <m)
        return true;
    else
        return false;
}
void dbfs ()
{
    int i, tq, tw;
    queue <node> q, w;//Two queues
    start.x = sx; start.y = sy;
    end.x = ex; end.y = ey;
    q.push (start);
    w.push (end);              
    vis1 [sx] [sy] = 0;//The following steps are added from 0
    vis2 [ex] [ey] = 0;
    while (! q.empty () &&! w.empty ())
    {
        node now, next;
        tq = q.size ();//In order to judge all of a queue first 
        while (tq--)
        {
          now = q.front ();
          q.pop ();
          if (inside (now.x, now.y) && vis2 [now.x] [now.y]! =-1)//Both ends have passed this point. .
          {
              printf ("% d\n", vis1 [now.x] [now.y] + vis2 [now.x] [now.y]);
              return;
          }
          for (i = 0; i <8; i ++)
          {
              next.x = now.x + fx1 [i];
              next.y = now.y + fx2 [i];
              if (inside (next.x, next.y) && vis2 [next.x] [next.y]! =-1)//Important, because of the odd steps. . .
              {
                  printf ("% d\n", vis1 [now.x] [now.y] + 1 + vis2 [next.x] [next.y]);
                  return;
              }
              if (inside (next.x, next.y) && vis1 [next.x] [next.y] ==-1)
              {
                  vis1 [next.x] [next.y] = vis1 [now.x] [now.y] +1;
                  q.push (next);
              }
          }
        }
        tw = w.size ();
        while (tw--)//Same as above
        {
          now = w.front ();
          w.pop ();
          if (inside (now.x, now.y) && vis1 [now.x] [now.y]! =-1)
          {
              printf ("% d\n", vis1 [now.x] [now.y] + vis2 [now.x] [now.y]);
              return;
          }
          for (i = 0; i <8; i ++)
          {
              next.x = now.x + fx1 [i];
              next.y = now.y + fx2 [i];
              if (inside (next.x, next.y) && vis1 [next.x] [next.y]! =-1)
              {
                  printf ("% d\n", vis2 [now.x] [now.y] + 1 + vis1 [next.x] [next.y]);
                  return;
              }
              if (inside (next.x, next.y) && vis2 [next.x] [next.y] ==-1)
              {
                  vis2 [next.x] [next.y] = vis2 [now.x] [now.y] +1;
                  w.push (next);
              }
          }
        }
    }
}
int main ()
{
    int t;
    scanf ("% d", & t);
    while (t--)
    {
        scanf ("% d", & m);
        scanf ("% d% d% d% d", & sx, & sy, & ex, & ey);
        memset (vis1, -1, sizeof (vis1));//Mark as not passed
        memset (vis2, -1, sizeof (vis2));
        dbfs ();
    }
        return 0;
}