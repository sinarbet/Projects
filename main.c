//
//  main.c
//  Betul
//
//  Created by Betül Şinar on 29.12.2018.
//  Copyright © 2018 Betül Şinar. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int i,j,k,matris[4][4],degisken_1,degisken_2,empty_number,max_number,end_score,new_record,flag;
    char movement;
    empty_number=16;
    max_number=0;
    end_score=0;
    new_record=0;
    flag=1;
    srand(time(NULL));
    
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            matris[i][j]=0;
        }
    }
    printf(" 2048 Oyununa hoşgeldiniz... \n ");
    
    while(empty_number>0 && max_number<2048){
        degisken_1=rand()%4;
        degisken_2=rand()%4;
    
            if(matris[degisken_1][degisken_2] == 0){
                matris[degisken_1][degisken_2]=2;
                empty_number--;//Controling the matris full of or not.
            }
            else continue;
        for(i=0;i<4;i++){
            printf("\n");
            printf("--------------------");
            printf("\n");
            for(j=0;j<4;j++){
                printf(" %d",matris[i][j]);
                printf("  |");
            }
        }
        printf("\n Score: %d", end_score);
        printf("\n direction?");
        printf("\n please enter for Move UP (w), DOWN (s), LEFT (a), RİGHT (d) \n");
        scanf(" %c",&movement);
        switch(movement){
            case('w'):                  //MOVE UP PART
                for(i=1;i<4; i++){
                    for(j=0;j<4; j++){
                        if(matris[i][j]!=0)
                        {
                            if(matris[i][j]==matris[i-1][j]){
                                matris[i-1][j]=2*matris[i][j];
                                matris[i][j]=0;
                                empty_number++;
                                end_score+=matris[i-1][j];
                            }
                            for(k=0;k<i;k++){  //En üstteki boşluğu arayıp oraya kadar kaydırma.
                                if(matris[k][j] == 0)
                                {
                                    matris[k][j]=matris[i][j];
                                    matris[i][j]=0;
                                }
                            }
                        }
                    }
                }
                break;
                
            case('s'):                  //MOVE DOWN PART
                for(i=0;i<3;i++){
                    for(j=0;j<4;j++){
                        if(matris[i][j]!=0)
                        {
                            if(matris[i][j]==matris[i+1][j]){
                                matris[i+1][j]=2*matris[i][j];
                                matris[i][j]=0;
                                empty_number++;
                                end_score+=matris[i+1][j];
                            }
                            for(k=3; k>i; k--){
                                if(matris[k][j] == 0)
                                {
                                    matris[k][j]=matris[i][j];
                                    matris[i][j]=0;
                                }
                            }
                        }
                    }
                }
                break;
                
            case('d'):                    //MOVE RİGHT PART
                for(i=0;i<4;i++){
                    for(j=2;j>-1;j--){
                        if(matris[i][j]!=0)
                        {
                            if(matris[i][j+1]==matris[i][j]){
                                matris[i][j+1]=2*matris[i][j];
                                matris[i][j]=0;
                                empty_number++;
                                end_score+=matris[i][j+1];
                            }
                            for(k=3; k>j; k--){
                                if(matris[i][k] == 0)
                                {
                                    matris[i][k]=matris[i][j];
                                    matris[i][j]=0;
                                    
                                }
                            }
                        }
                    }
                }
                break;
                
                
            case('a'):                  //MOVE LEFT PART
                for(i=0;i<4;i++)
                {
                    for(j=1;j<4;j++)
                    {
                        if(matris[i][j]!=0)
                        {
                            if(matris[i][j-1]==matris[i][j]){
                                matris[i][j-1]=2*matris[i][j];
                                matris[i][j]=0;
                                empty_number++;
                                end_score+=matris[i][j-1];
                            }
                            for(k=0; k<j; k++){
                                if(matris[i][k]==0)
                                {
                                    matris[i][k]=matris[i][j];
                                    matris[i][j]=0;
                                    
                                }
                            }
                        }
                    }
                }
                break;
            case('e'):
                empty_number=0;
                break;
            default:
                flag=0;
                printf("Yanlış bir komut girdiniz! \n");
        }
        for(i=0;i<4;i++){        //CONTROLİNG TOTAL NUMBER<2048
            for(j=0;j<4;j++){
                if(matris[i][j] == 2048)
                    max_number=2048;
            }
        }
    }
    if(empty_number==0){
        printf("\n GAME OVER. Score: %d \n",end_score);
    }
    if (end_score > new_record){
           new_record=end_score;
        printf("NEW HİGH SCORE = %d \n ",new_record);
    }
        
    if(max_number == 2048){
        printf("YOU WİN. CONGRATS... :)");
        printf("%d",end_score);
        
    }
    printf("Are you want to play new game? For new game please 'r' for quit ---> 'e' ");
    return 0;
}
