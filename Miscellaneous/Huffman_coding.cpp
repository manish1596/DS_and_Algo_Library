#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>

struct node{
node* r;
node* l;
std::string s;
int freq;
std::string code="";
};

struct compare
 {
   bool operator()(const node& l, const node& r)
   {
       return l.freq > r.freq;
   }
 };

 void print_codes(node* n){
    if(n->l==NULL && n->r==NULL){
        std::cout << n->s << " : " << n->code << "\n";
        return;
    }
    else{
        (n->l)->code=n->code+"0";
        print_codes(n->l);
        (n->r)->code=n->code+"1";
        print_codes(n->r);
    }
 }



int main()
    {
        int n, i, j, freq1, freq2;
        std::priority_queue< node, std::vector<node>, compare > Q;
        node n1, n2, temp;
        node alpha[200];
        std::string s1("cas"),s2("hier");
        /*n1.s="a";
        n1.r=1;
        n1.l=9;
        n1.freq=2;
        n2.s="b";
        n2.r=4;
        n2.l=6;
        n2.freq=5;
        Q.push(n1);
        Q.push(n2);*/
        //std::cout << (Q.top()).freq;
        std::cin >> n;
        for(i=0; i<n; i++){
            std::cin >> temp.s;

            std::cin >> temp.freq;
            temp.r=NULL;
            temp.l=NULL;
            temp.code="";
            Q.push(temp);
        }
        i=0;
        while(Q.size()!=1){
            alpha[i++]=Q.top();
            Q.pop();
            alpha[i++]=Q.top();
            Q.pop();
            temp.s=alpha[i-2].s+alpha[i-1].s;
            temp.freq=alpha[i-2].freq+alpha[i-1].freq;
            temp.l=&alpha[i-2];
            temp.r=&alpha[i-1];
            Q.push(temp);
        }
        node root=Q.top();
        Q.pop();
        root.code="";
        //std::cout << (((root.l)->l)->r)->freq;
        //std::cout << (root.l)->l->freq;
        //std::cout << (root.l)->l->s;
        //std::cout << (((root.l)->l)->r)->s;
        print_codes(&root);
        //std::cout << temp.s;
        //std::cout << temp.freq;
        //std::cout << s1+s2;
    }
