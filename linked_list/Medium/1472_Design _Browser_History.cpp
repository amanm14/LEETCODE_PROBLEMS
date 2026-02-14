struct nod{
    string data;
    nod*next;
    nod*prev;
    nod(string&val){
         data=val;
         next=NULL;
         prev=NULL;
    }
    nod(){
        data="";
        next=NULL;
        prev=NULL;
    }
};

class BrowserHistory {
public://O(S) is the number of steps we take and O(N) is the sapce complexity the number of nodes that we create

    int size=0;
    nod*head=new nod();
    nod*n=head;

    BrowserHistory(string homepage) {
        head->data=homepage;
        head->next=NULL;
        head->prev=NULL;
    }
    
    void visit(string url) {
        nod*n1=new nod(url);
        head->next=n1;
        n1->prev=head;

        head=n1;

        return;
    }
    
    string back(int steps) {
        // cout<<head->data<<" check "<<steps<<" "<<endl;
        // cout<<head->prev->data<<" "<<endl;
        while(steps>0&&head->prev!=NULL){
            head=head->prev;
            // cout<<head->data<<" check1 "<<endl;
            steps--;
        }
        return head->data;
    }
    
    string forward(int steps) {

        int i=0;
        while(i<steps&&head->next!=NULL){
            // cout<<head->data<<" check1 "<<endl;
            head=head->next;
            i++;
        }
        return head->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
