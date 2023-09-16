#include <iostream>

using namespace std;

char ** q3a(char * str, int * size){
    
    char ** result;
    
    int cnt = 1;
    for(int i=0;i<*size;i++){
        if(str[i]==' '){
            cnt++;
        }
    }
    result = new char * [cnt];
    *size=cnt;

    cnt=0;
    int indexer;
    indexer=0;
    int startIndexer;
    startIndexer=0;

    for(int j=0;j<*size;j++){
        while(str[indexer]!=' '&&str[indexer]!='\0'){
            indexer++;
            cnt++;
        }
        cnt++;
        indexer++;

        result[j] = new char[cnt];

        for(int k=startIndexer;k<startIndexer+(cnt)-1;k++){
            result[j][k-startIndexer]=str[k];
        }
        startIndexer+=(cnt);
        
        result[j][cnt]='\0';
        cnt=0;
    }
    return result;
}

char * newStr(char * str){
    int cnt=1;
    while(str[cnt]!='\0'){
        cnt++;
    }
    char * p = new char[cnt*2];
    for(int i=0;i<cnt*2;i++){
        if(i<cnt){
            p[i]=str[i];
        }else{
            p[i]=str[i-cnt];
        }
    }
    return p;
}

int main(){

    int size = 18;
    char sentence[] = "Omri is ahla gever";
    char ** result = q3a(&sentence[0],&size);

    for(int i=0;i<size;i++){
        cout<<newStr(&result[i][0])<<endl;
    }
    return 0;
}