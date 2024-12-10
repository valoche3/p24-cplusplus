class Integer{
    private:
        int value{};  
    public:  
        void incr(){
            value=value+1;
        }
        Integer (int v){
            value=v;
        }
};

int main(){
    Integer i;
    Integer j=i;
    i=j;
    i.incr();
}