#include<iostream>
using namespace std;
class WquickUnion
{
    private:
    int arr[10];
    int size_arr[10];
    public:
    WquickUnion()
    {
        for(int i=0;i<10;i++)
        {
            arr[i]=i;
            size_arr[i]=1;
        }
    }
    int root(int el)
    {
        if(el<0||el>9)
        {
            return -1;
        }
        int root_id=arr[el];
        while(arr[root_id]!=root_id)
        {
            root_id=arr[root_id];
        }
        return root_id;
    }
    int union_el(int el1,int el2)
    {
        if(el1<0||el1>9||el2<0||el2>9)
        {
            cout<<"Wrong input";
            return 0;
        }
        int el1_root=root(el1);
        int el2_root=root(el2);
        if(el1_root==el2_root)
        {
            return 1;
        }
        if(size_arr[el1_root]<=size_arr[el2_root])
        {
            arr[el1_root]=arr[el2_root];
            size_arr[el2_root]+=size_arr[el1_root];
        }
        else
        {
            arr[el2_root]=arr[el1_root];
            size_arr[el1_root]+=size_arr[el2_root];
        }
        return 2;
    }
    bool connected(int el1,int el2)
    {
        if(el1<0||el1>9||el2<0||el2>9)
        {
            cout<<"Wrong input"<<endl;
            return false;
        }
        int el1_root=root(el1);
        int el2_root=root(el2);
        if(el1_root==el2_root)
        {
            return true;
        }
        else
            return false;
    }
    int components()
    {
        int count=0;;
        for(int i=0;i<10;i++)
        {
            if(arr[i]==i)
                count++;
        }
        return count;
    }

};
void f_union(WquickUnion &);
void f_components(WquickUnion &);
void f_connected(WquickUnion &);
int main()
{
    WquickUnion a;
    char ch;
    cout<<"To stop enter q"<<endl;
    do{
        cout<<"Enter U for union \nEnter C to if two objects are connected \nEnter N for no. of components"<<endl;
        cin>>ch;
        if(ch=='q'||ch=='Q')
            break;
        switch(toupper(ch))
        {
            case 'U':f_union(a);
            break;
            case 'C':f_connected(a);
            break;
            case 'N':f_components(a);
            break;
            default:cout<<"Wrong choice"<<endl;
            break;
        }
    }while(ch!='q'||ch!='Q');
}
void f_union(WquickUnion &b)
{
    int n1,n2;
    cout<<"Enter Objects to take union"<<endl;
    cin>>n1>>n2;
    int ret_value=b.union_el(n1,n2);
    if(ret_value==0)
    {
        cout<<"You entered wrong objects"<<endl;
    }
    else if(ret_value==1)
    {
        cout<<"already connected"<<endl;
    }
    else if(ret_value==2)
    {
        cout<<"Connected"<<endl;
    }
}
void f_connected(WquickUnion &b)
{
    int n1,n2;
    cout<<"Enter the two objects"<<endl;
    cin>>n1>>n2;
    if(b.connected(n1,n2))
    {
        cout<<"Connected"<<endl;
    }
    else
        cout<<"Not Connected"<<endl;
}
void f_components(WquickUnion &b)
{
    int n=b.components();
    cout<<n<<endl;
}
