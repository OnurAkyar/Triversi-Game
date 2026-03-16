#include<stdio.h>
#define N 25
int  boyut; //hem void hem de main fonksiyonda kullanildigi icin global olarak tanimlandi.

//etrafini kontrol edip renkleri boyamak icin ve daha anlasilir gozukmesi icin fonksiyon kullaniyoruz.
void controlfunc(int i,int j,char matris[N][N]){
    int found,tempsutun,tempsatir,isvalid; 
    char temp;

    //siradaki rengi ve kullanicinin bize girdigi i ve j leri tutuyoruz.
    //i ve j ler degistikten sonra tuttugumuz orijinal i ve j leri geri atayacagiz.
    temp=matris[i][j];
    tempsatir=i;
    tempsutun=j;
    found=0;
    isvalid=0;

    //matrisin etrafina 1 den boyuta kadar numaralari yazdiriyoruz oyuncu daha rahat sayi girebilmesi icin.
    printf("  ");
    for(i=1;i<=boyut;i++){
        printf("%2d",i);
    }
    printf("\n");
    //matrisin boyanmamis halini her seferinde yazdiriyoruz.
    for(i=0;i<boyut;i++){
        printf("%2d",i+1);
        for(j=0;j<boyut;j++){
            printf("%2c",matris[i+1][j+1]);
        }
        printf("\n");
    }
    i=tempsatir;
    j=tempsutun;

     //ust icin kontrol yapiyoruz.
    while(i>0 && matris[i-1][j]!='*' && temp!=matris[i-1][j]){
        i--;
        found=1;
    }
    if(temp==matris[i-1][j] && found==1){ //temp ile matris esitse ve oncesinde while'a girip found=1 ise boyama islemi yapiyoruz.
        isvalid=1;
        while(i<tempsatir){ 
            matris[i][j]=temp;
            i++;
        }
    }
    found=0;
    i=tempsatir;

    //sag icin kontrol yapiyoruz.
    while(j<boyut-1 && matris[i][j+1]!='*' && temp!=matris[i][j+1]){
        j++;
        found=1;
    }
    if(temp==matris[i][j+1] && found==1){
        isvalid=1;
        while(j>tempsutun){
            matris[i][j]=temp;
            j--;
        }
    }
    found=0;
    j=tempsutun;

    //asagi icin kontrol yapiyoruz.
    while(i<boyut-1 && matris[i+1][j]!='*' && temp!=matris[i+1][j]){
        i++;
        found=1;
    } 
    if(temp==matris[i+1][j] && found==1){
        isvalid=1;
        while(i>tempsatir){
            matris[i][j]=temp;
            i--;
        }
    }
    found=0;
    i=tempsatir;

    //sol icin kontrol yapiyoruz.
    while(j>0 && matris[i][j-1]!='*' && temp!=matris[i][j-1]){
        j--;
        found=1;
    }
    if(temp==matris[i][j-1] && found==1){
        isvalid=1;
        while(j<tempsutun){
            matris[i][j]=temp;
            j++;
        }
    }
    found=0;
    j=tempsutun;

    //sag yukari carpraz icin kontrol yapiyoruz.
    while(i>0 && j<boyut-1 && matris[i-1][j+1]!='*' && temp!=matris[i-1][j+1]){
        j++;
        i--;
        found=1;
    }
    if(temp==matris[i-1][j+1] && found==1){
        isvalid=1;
        while(j>tempsutun /*&& i<tempsatir*/){
            matris[i][j]=temp;
            j--;
            i++;
        }
    }
    found=0;
    i=tempsatir;
    j=tempsutun;

     //sag aşagi carpraz icin kontrol yapiyoruz.
    while(i<boyut-1 && j<boyut-1 && matris[i+1][j+1]!='*' && temp!=matris[i+1][j+1]){
        j++;
        i++;
        found=1;
    }
    if(temp==matris[i+1][j+1] && found==1){
        isvalid=1;
        while(j>tempsutun /*&& i>tempsatir*/){
            matris[i][j]=temp;
            j--;
            i--;
        }
    }
    found=0;
    i=tempsatir;
    j=tempsutun;

     //sol aşagi carpraz icin kontrol yapiyoruz.
    while(i<boyut-1 && j>0 && matris[i+1][j-1]!='*' && temp!=matris[i+1][j-1]){
        j--;
        i++;
        found=1;
    }
    if(temp==matris[i+1][j-1] && found==1){
        isvalid=1;
        while(j<tempsutun /*&& i<tempsatir*/){
            matris[i][j]=temp;
            j++;
            i--;
        }
    }
    found=0;
    i=tempsatir;
    j=tempsutun;

     //sol yukari carpraz icin kontrol yapiyoruz.
    while(i>0 && j>0 && matris[i-1][j-1]!='*' && temp!=matris[i-1][j-1]){
        j--;
        i--;
        found=1;
    }
    if(temp==matris[i-1][j-1] && found==1){
        isvalid=1;
        while(j<tempsutun /*&& i<tempsatir*/){
            matris[i][j]=temp;
            j++;
            i++;
        }
    }
    found=0;
    i=tempsatir;
    j=tempsutun;

    //matrisde boyama islemi olduysa matrisi tekrar yazdiriyoruz.
    if(isvalid==1){//isvali==1 matrisin boyandigini ya da boyanmadigini gosteriyor.
      printf("\n");
      printf("%c rengi taslari boyadi.",temp);
      printf("\n");
      printf("  ");
    for(i=1;i<=boyut;i++){
        printf("%2d",i);
    }
    printf("\n");
    for(i=0;i<boyut;i++){
        printf("%2d",i+1);
        for(j=0;j<boyut;j++){
            printf("%2c",matris[i+1][j+1]);
        }
        printf("\n");
        }
    
    }
}

int main(){
    int i,j,counter=0,k,l,dogru=0,K=0,S=0,M=0;
    char matris[N][N];
    printf("Oynamak istediginiz oyun tahtasinin boyutunu giriniz(1-23 arasinda):\n");
    scanf("%d",&boyut);
    for(i=0;i<N;i++){//matrisimi * ile dolduruyorum.
        for(j=0;j<N;j++){
            matris[i][j]='*';
        }
    }
    printf("╔════════════════════════╗\n");
    printf("║        TRIVERSI        ║\n");
    printf("╚════════════════════════╝\n");

    //oyun tahtasi tek boyut ise oyun kirmizi ile otomatik basliyor.
    if(boyut%2==1){
        i=boyut/2;
        j=boyut/2;
        matris[i+1][j+1]='K';
    }else{
        //degilse kirmizi oyuncu oyun tahtasinin ortasina en yakin yeri secene kadar secim sunulur.
        k=boyut/2;
        l=boyut/2+1;
        while(dogru==0){
        printf("(%d)(%d),(%d)(%d),(%d)(%d),(%d)(%d) koordinatlarindan birini giriniz:",k,k,k,l,l,k,l,l);
        scanf("%d %d",&i,&j);
        if(i<=l && i>=k && j<=l && j>=k){
            matris[i][j]='K';
            dogru=1;
        }
        }
    }    
    //oyun tahtasinin ilk tas koyulduktan sonraki hali yazdirilir.
    printf("  ");
    for(i=1;i<=boyut;i++){
        printf("%2d",i);
    }
    printf("\n");

    for(i=0;i<boyut;i++){
        printf("%2d",i+1);
        for(j=0;j<boyut;j++){
            printf("%2c",matris[i+1][j+1]);
        }
        printf("\n");
    }
    printf("\n");
    //etrafinda tas var mi kontrolunu yaparken matris disina tasmamak icin matrisin etrafina * cercevesi yapiyoruz.
    for(j=0;j<=boyut;j++){
        matris[0][j]='*';
        matris[boyut+1][j]='*';
    }
    for(i=0;i<=boyut;i++){
        matris[i][0]='*';
        matris[i][boyut+1]='*';
    }

    //oyun tahtasinin goz sayisinin bir eksigi kadar oyun devam eder.En basta kirmizi oyuncu ilk tasi koymustu.
    while(counter<boyut*boyut-1){

        //oyuncular icin kontroller yapilir ve fonksiyon cagirilarak kontrol etme islemleri baslar.
        if(counter<boyut*boyut-1){
        printf("2.oyuncunun(Sari) sirasi:");
        scanf("%d %d",&i,&j);
        //matrisin sinir boyutlarini kontrol ediyoruz ve oyuncunu sectigi koordinatda baska tas var ise gecersiz hamle oluyor.
        if(matris[i][j]=='*' && i>0 && j>0 && i<=boyut && j<=boyut){
            //oyuncunun sectigi koordinatlarda 8 komsuda baska tas var mi diye kontrol ediyoruz.Yok ise gecersiz hamle oluyor.
        if(matris[i-1][j]!='*' || matris[i][j+1]!='*' || matris[i+1][j]!='*' || matris[i][j-1]!='*' || matris[i-1][j+1]!='*' || matris[i+1][j+1]!='*' || matris[i+1][j-1]!='*' || matris[i-1][j-1]!='*'){
                matris[i][j]='S';
                controlfunc(i,j,matris);
                printf("\n");
                counter++;
            }else printf("Gecersiz hamle.Hamle sirasi siradaki oyuncuda.\n");
        }else printf("Gecersiz hamle.Hamle sirasi siradaki oyuncuda.\n");
        }

        //sira 3.oyuncuya geciyor.
        if(counter<boyut*boyut-1){
        printf("3.oyuncunun(Mavi) sirasi:");
        scanf("%d %d",&i,&j);
        if(matris[i][j]=='*' && i>0 && j>0 && i<=boyut && j<=boyut){
        if(matris[i-1][j]!='*' || matris[i][j+1]!='*' || matris[i+1][j]!='*' || matris[i][j-1]!='*' || matris[i-1][j+1]!='*' || matris[i+1][j+1]!='*' || matris[i+1][j-1]!='*' || matris[i-1][j-1]!='*'){
                matris[i][j]='M';
                controlfunc(i,j,matris);
                printf("\n");
                counter++;
            }else printf("Gecersiz hamle.Hamle sirasi siradaki oyuncuda.\n");
        }else printf("Gecersiz hamle.Hamle sirasi siradaki oyuncuda.\n");
        }

        //sira 1.oyuncuya gecerek oyun basa donuyor ve tum gozler dolana kadar bu sekilde devam ediyor.
        if(counter<boyut*boyut-1){
        printf("1.oyuncunun(Kirmizi) sirasi:");
        scanf("%d %d",&i,&j);
        if(matris[i][j]=='*' && i>0 && j>0 && i<=boyut && j<=boyut){
        if(matris[i-1][j]!='*' || matris[i][j+1]!='*' || matris[i+1][j]!='*' || matris[i][j-1]!='*' || matris[i-1][j+1]!='*' || matris[i+1][j+1]!='*' || matris[i+1][j-1]!='*' || matris[i-1][j-1]!='*'){
                matris[i][j]='K';
                controlfunc(i,j,matris);
                printf("\n");
                counter++;
            }else printf("Gecersiz hamle.Hamle sirasi siradaki oyuncuda.\n");
        }else printf("Gecersiz hamle.Hamle sirasi siradaki oyuncuda.\n");
        }
    }
    printf(" -------------\n");
    printf("| OYUN BİTTİ |\n");
    printf(" -------------\n");
    
    for(i=0;i<boyut;i++){
        for(j=0;j<boyut;j++){
        if(matris[i+1][j+1]=='K'){
            K++;
        }else{
            if(matris[i+1][j+1]=='S'){
                S++;
            }else{
                M++;
            }
        }
        }
    }
    printf("Kirmizi renkten %d tane var.\n",K);
    printf("Sari renkten %d tane var.\n",S);
    printf("Mavi renkten %d tane var.\n",M);
    
    printf(" -------------------------------------- \n ");//kazanan veya berabere kalanlar yazdirilir.
    if(K>=S){
        if(K==S){
            if(K>M){
                printf("---🎉 1.oyuncu(Kirmizi) ve 2.oyuncu(Sari) berabere 🎉---");
            }else{
                if(K==M){
                    printf("--- 🎉Tum oyuncular berabere🎉 ---");
                }else printf("--- 🎉Kazanan oyuncu:3.OYUNCU(MAVİ)🎉 ---");
            }
        }else{
            if(K>M){
                printf("---🎉 Kazanan oyuncu:1.OYUNCU(KİRMİZİ) 🎉---");
            }else{
                if(K==M){
                    printf("--- 🎉1.oyuncu(Kirmizi) ve 3.OYUNCU(Mavi) berabere🎉 ---");
                }else printf("--- 🎉Kazanan oyuncu:3.OYUNCU(MAVİ)🎉 ---");
            }
        }
    }else{
        if(S>M){
            printf("--- 🎉Kazanan oyuncu:2.OYUNCU(SARİ)🎉 ---");
        }else{
            if(S==M){
                printf("--- 🎉2.oyuncu(Sari) ve 3.oyuncu(Mavi) berabere🎉 ---");
            }else printf("--- 🎉Kazanan oyuncu:3.OYUNCU(MAVİ)🎉 ---");
        }
    }
    printf("\n");
    printf(" -------------------------------------- ");
    return 0;
}
