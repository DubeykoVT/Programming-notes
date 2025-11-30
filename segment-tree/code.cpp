#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e10;

struct Node {
    int x, push, sz;
    Node(int a = 0, int b = 0, int c = 0) : x(a), push(b), sz(c) {}
    Node operator+(Node a) { return Node(x + a.x, 0, sz + a.sz); }
};

Node NullN(0, 0, 0);

struct Tree {
    vector<Node> a, t;
    Tree(vector<Node> x) {
        a = x;
        t.assign(4 * x.size(), Node());
        build(0,0,a.size());
    }

    void build(int v, int l, int r) {
        if (l + 1 == r) {
            t[v] = a[l];
            t[v].sz = 1;
            return;
        }
        int mid = (l+r)/2;
        build(2*v+1,l,mid);
        build(2*v+2,mid,r);
        t[v] = t[2*v+1] + t[2*v+2];
    }

    void push(int v) {
        t[2*v+1].push += t[v].push;
        t[2*v+1].x += t[v].push * t[2*v+1].sz;
        t[2*v+2].push += t[v].push;
        t[2*v+2].x += t[v].push * t[2*v+2].sz;
        t[v].push = 0;
    }

    Node get(int v, int l, int r, int l1, int r1) {
        if (l>=l1 && r<=r1) return t[v];
        if (l>=r1 || r<=l1) return NullN;
        push(v);
        int mid=(l+r)/2;
        return get(2*v+1,l,mid,l1,r1)+get(2*v+2,mid,r,l1,r1);
    }

    void update_pos(int v,int l,int r,int pos,int val){
        if(l+1==r){t[v].x=val;return;}
        push(v);
        int mid=(l+r)/2;
        if(pos<mid) update_pos(2*v+1,l,mid,pos,val);
        else update_pos(2*v+2,mid,r,pos,val);
        t[v]=t[2*v+1]+t[2*v+2];
    }

    void add_seg(int v,int l,int r,int l1,int r1,int val){
        if(l>=l1 && r<=r1){
            t[v].x+=val*t[v].sz;
            t[v].push+=val;
            return;
        }
        if(l>=r1 || r<=l1) return;
        push(v);
        int mid=(l+r)/2;
        add_seg(2*v+1,l,mid,l1,r1,val);
        add_seg(2*v+2,mid,r,l1,r1,val);
        t[v]=t[2*v+1]+t[2*v+2];
    }

public:
    Node get(int l,int r){return get(0,0,a.size(),l,r);}
    void update(int pos,int val){update_pos(0,0,a.size(),pos,val);}
    void add(int l,int r,int val){add_seg(0,0,a.size(),l,r,val);}
};
