int result (int x, int y){
    return (x > y ) ? x - y: y - x;
}

int main(){
    printf("%d\n",result(6, 5));
    return 0;
}