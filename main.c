#include <stdio.h>
#include <stdlib.h>

void Turkiye_Hesaplama(int il_oy[], char il_parti[], int il_kontenjan[],int t_oy[], char t_parti[], int t_kontenjan[], int t_birincilik[], int t_sifir[]);
void Parti_adlandirma(char partiadi[]);
void Turkiye_geneli_siralama(int oy[],int mv[],char ad[], int birincilik[], int sifir[]);

int main()
{

    int plaka_kodu,mv_kontenjani=0,partisay[8]={0},a,b,en_fazla=0,mv_say[8]={},t,tut,partisay2[8]={},tut2;
    char partiadi[8],adtut,t_parti[8];
    float toplamoy=0;
    int t_oy[8],t_kontenjan[8],t_birincilik[8], t_sifir[8];

    for(int i=0; i<8; i++)
    {
        mv_say[i]=0;
        t_oy[i]=0;
        t_kontenjan[i]=0;
        t_birincilik[i]=0;
        t_sifir[i]=0;
    }

    Parti_adlandirma(t_parti);

    while(1)
    {
    Parti_adlandirma(partiadi);
    printf("Ilin plaka kodunu giriniz:");
    scanf("%d",&plaka_kodu);
    if(plaka_kodu==0)
        break;
    printf("Milletvekili kontenjanini giriniz:");
    scanf("%d",&mv_kontenjani);
        for(a=0;a<8;a++){
            printf("%c partisinin oy sayisi:",partiadi[a]);
            scanf("%d",&partisay[a]);  toplamoy+=partisay[a]; }

        for(a=0;a<8;a++){
            partisay2[a]=partisay[a];}


        for(b=0;b<mv_kontenjani;b++){
            en_fazla=0;
            t=0;

        for(a=0;a<8;a++){

            if(en_fazla<partisay2[a]){
                en_fazla=partisay2[a];
                t=a;
            }

            }
             partisay2[t]=partisay2[t]/2;
                mv_say[t]++;
            }
          for(a=0;a<7;a++){
            for(b=0;b<7-a;b++)
                if(partisay[b]<partisay[b+1]){
                    tut=partisay[b];
                    partisay[b]=partisay[b+1];
                    partisay[b+1]=tut;
                    adtut=partiadi[b];
                    partiadi[b]=partiadi[b+1];
                    partiadi[b+1]=adtut;
                    tut2=mv_say[b];
                    mv_say[b]=mv_say[b+1];
                    mv_say[b+1]=tut2;}}

        Turkiye_Hesaplama(partisay,partiadi,mv_say,t_oy,t_parti,t_kontenjan,t_birincilik,t_sifir);

        printf("\nilin plaka kodu:%d",plaka_kodu);
        printf("\nilin milletvekili kontenjan sayisi:%d",mv_kontenjani);
        printf("\nGecerli oy sayisi:%.0f\n",toplamoy);
        printf("Parti adi      oy sayisi      oy yuzdesi     milletvekili sayisi\n");
        printf("---------      ---------      ----------     -------------------\n\n");
        for(a=0;a<8;a++){
                printf("%c            %d              %.2f            %d\n",partiadi[a],partisay[a],partisay[a]*100/toplamoy,mv_say[a]);}
    }
    Turkiye_geneli_siralama(t_oy,t_kontenjan,t_parti,t_birincilik,t_sifir);
            printf("\t*******Ulke geneli*********\n");
            printf("Parti adi      toplam oy sayisi      toplam milletvekili sayisi      il birincilik sayisi      0 milletvekili il sayisi \n");
            printf("---------      ----------------      --------------------------      --------------------      ------------------------\n");
    for(int i=0; i<8;i++)
        printf("%c               %d                     %d                              %d                          %d\n",t_parti[i],t_oy[i], t_kontenjan[i],t_birincilik[i],t_sifir[i]);

    printf("iktidar parti: %c\n",t_parti[0]);
    printf("Ana mulafet partisi: %c",t_parti[1]);
}

void Turkiye_Hesaplama(int il_oy[], char il_parti[], int il_kontenjan[],int t_oy[], char t_parti[], int t_kontenjan[],int t_birincilik[], int t_sifir[])
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8;j++)
        {
            if(t_parti[i] == il_parti[j])
            {
                if(j==0)
                    t_birincilik[i]++;

                if(il_kontenjan[j]==0)
                    t_sifir[i]++;

                t_kontenjan[i]+=il_kontenjan[j];
                t_oy[i]+=il_oy[j];
                break;
            }
        }
    }
}

void Parti_adlandirma(char partiadi[])
{
    char harfler[] = {'A','B','C','D','E','F','G','H'};
    for(int i=0; i<8;i++)
        partiadi[i]=harfler[i];
}

void Turkiye_geneli_siralama(int oy[],int mv[],char ad[], int birincilik[], int sifir[])
{
    int gecici, gecici1,gecici2, gecici3,gecici5;
    char gecici4;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8-1-i; j++)
        {
            if(oy[j] < oy[j+1])
            {
                gecici =  oy[j];
                oy[j] = oy[j+1];
                oy[j+1] = gecici;

                gecici2 =  mv[j];
                mv[j] = mv[j+1];
                mv[j+1] = gecici2;

                gecici3 =  birincilik[j];
                birincilik[j] = birincilik[j+1];
                birincilik[j+1] = gecici3;

                gecici4 =  ad[j];
                ad[j] = ad[j+1];
                ad[j+1] = gecici4;

                gecici1 =  sifir[j];
                sifir[j] = sifir[j+1];
                sifir[j+1] = gecici1;
            }
        }
    }
}
