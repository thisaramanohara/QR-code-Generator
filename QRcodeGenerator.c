#include<stdio.h>
#include<string.h>

// functions prototypes
void ch(unsigned char letter,int row ,int col,int colour); //to colour a full bit
int * orderd_array(unsigned char * arr); //to get the hashed string
void box();               // to print a white box
void black(int col);      // to print a specified coloured box
void position(int start_row, int start_col,int colour);     //to draw position identification square


int main(int argc , char *argv[]){
        int colour;     //variable for colour
        if(argc>3){
            printf("Incorrect usage of arguments.\n");
            printf("usage :\n");
            printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
            printf("%s -h for the help about the program\n",argv[0]);

            return 0;
        }
        else if(argc==2){
            if(argv[1][0]=='-' && argv[1][1]=='h' && argv[1][2]=='\0' ){
                printf("usage :\n");
                        printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
                        printf("%s -h for the help about the program\n",argv[0]);
                return 0;
            }
            else if(argv[1][0]=='-'&& argv[1][1]=='c'){
                printf("Incorrect usage of arguments.\n");
                    printf("usage :\n");
                    printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
                    printf("%s -h for the help about the program\n",argv[0]);	
                return 0;
            }
            else{
                printf("Incorrect usage of arguments.\n");
                    printf("usage :\n");
                    printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
                    printf("%s -h for the help about the program\n",argv[0]);
                return 0;
            }
        
        }
        else if(argc==3){
            if(argv[1][0]=='-' && argv[1][1]=='c'){
                if((argv[2][0]=='b'||argv[2][0]=='B')&& (argv[2][1]=='l'||argv[2][1]=='L')&& (argv[2][2]=='a'||argv[2][2]=='A')&& (argv[2][3]=='c'||argv[2][3]=='C')&& (argv[2][4]=='k'||argv[2][4]=='K') && argv[2][5]=='\0' ){
                    colour = 1;  // 1 for black
                }else if((argv[2][0]=='r'||argv[2][0]=='R')&& (argv[2][1]=='e'||argv[2][1]=='E')&& (argv[2][2]=='d'||argv[2][2]=='D') && argv[2][3]=='\0' ){
                    colour =2; // 2 for red
                }else if((argv[2][0]=='g'||argv[2][0]=='G')&& (argv[2][1]=='r'||argv[2][1]=='R')&& (argv[2][2]=='e'||argv[2][2]=='E')&& (argv[2][3]=='e'||argv[2][3]=='E')&& (argv[2][4]=='n'||argv[2][4]=='N') && argv[2][5]=='\0' ){
                    colour =3; //3 for green
                }else if((argv[2][0]=='y'||argv[2][0]=='Y')&& (argv[2][1]=='e'||argv[2][1]=='E')&& (argv[2][2]=='l'||argv[2][2]=='L')&& (argv[2][3]=='l'||argv[2][3]=='L')&& (argv[2][4]=='o'||argv[2][4]=='O')&& (argv[2][5]=='w'||argv[2][5]=='W') && argv[2][6]=='\0' ){
                    colour =4;  //4 for yellow
                }else if((argv[2][0]=='b'||argv[2][0]=='B')&& (argv[2][1]=='l'||argv[2][1]=='L')&& (argv[2][2]=='u'||argv[2][2]=='U')&& (argv[2][3]=='e'||argv[2][3]=='E') && argv[2][4]=='\0' ){
                    colour =5;  //5 for blue
                }else if((argv[2][0]=='m'||argv[2][0]=='M')&& (argv[2][1]=='a'||argv[2][1]=='A')&& (argv[2][2]=='g'||argv[2][2]=='G')&& (argv[2][3]=='e'||argv[2][3]=='E')&& (argv[2][4]=='n'||argv[2][4]=='N')&& (argv[2][5]=='t'||argv[2][5]=='T')&& (argv[2][6]=='a'||argv[2][6]=='A') && argv[2][7]=='\0' ){
                    colour = 6; // 6 for magenta 
                }else if((argv[2][0]=='c'||argv[2][0]=='C')&& (argv[2][1]=='y'||argv[2][1]=='Y')&& (argv[2][2]=='a'||argv[2][2]=='A')&& (argv[2][3]=='n'||argv[2][3]=='N') && argv[2][4]=='\0' ){
                    colour = 7;  //7 for cyan
                }else{
                    printf("Invalid argument for color.\n");
                    printf("usage :\n");
                    printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
                    printf("%s -h for the help about the program\n",argv[0]);
                return 0;
                }
            
            }else{
                printf("Incorrect usage of arguments.\n");
                printf("usage :\n");
                    printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
                    printf("%s -h for the help about the program\n",argv[0]);
                            return 0;
            }
            
        }else if(argc==1){
            colour = 1;  //setting black
        }

        int i,j;  //for counting
        unsigned char URL_input[10000]={0};  //declaring the variable for input
        printf("Enter the URL: ");
        scanf("%s",URL_input);  //getting the input
        
    if(strlen((const char*)URL_input)<4){  //if input is short
            printf("String is too short. Not supported by available QR versions\n");
            return 0;
    }
    if(strlen((const char*)URL_input)>=120){  //if input is big
            printf("String is too long. Not supported by available QR versions\n");
            return 0;
    }

        printf("\e[1;1H\e[2J");  // clearing the screen
        
       int*URL;     //for the hashtagged string
    URL = orderd_array(URL_input);
    
    int count = 0;
    for(int i =0;URL[i]!='\0';i++){
        count++;
    }
    
    if(count==24){        //##############################################
   

    //creating the outer frame
    printf("\x1b[47m                                        \x1b[0m\n");
    for(i=0;i<18;i++){
        printf("\x1b[47m  \x1b[0m");
        printf("\033[36C");
        printf("\x1b[47m  \x1b[0m\n");
    }
    printf("\x1b[47m                                        \x1b[0m\n");

    //printing position boxes
    position(1,1,colour);   position(1,5,colour);   position(5,1,colour);

    //printing characters
    ch(URL[16],1,3,colour); ch(URL[17],1,4,colour); ch(URL[18],2,3,colour); ch(URL[19],2,4,colour);
    ch(URL[20],3,1,colour); ch(URL[21],3,2,colour); 
    ch(URL[22],4,1,colour); ch(URL[23],4,2,colour);
    
    int pre = 0;
    for(i=3;i<=6;i++){

        for(j=3;j<=6;j++){
            ch(URL[pre],i,j,colour);
            pre++;
        }
    }

        printf("\n");
        printf("\n"); //ending
    }
    //#########################################################
    else if (count==132){ 
        //creating the outer frame
    for(i=0;i<38;i++){    //printing the first line of the figure
            box();
        } 
        printf("\n");
    for(i=0;i<36;i++){
        printf("\x1b[47m  \x1b[0m");
        printf("\033[72C");
        printf("\x1b[47m  \x1b[0m\n");
    }
    
    for(i=0;i<38;i++){    //printing the lst line of the figure
            box();
        } 
        printf("\n");
    //printing position boxes
    position(1,1,colour);   position(1,11,colour);   position(11,1,colour);
    
    // printing characters
    int pre1 = 100;
    for(i=1;i<=2;i++){

        for(j=3;j<=10;j++){
            ch(URL[pre1],i,j,colour);
            pre1++;
        }
    }

    int pre2 = 116;
    for(i=3;i<=10;i++){

        for(j=1;j<=2;j++){
            ch(URL[pre2],i,j,colour);
            pre2++;
        }
    }

    int pre3 = 0;
    for(i=3;i<=12;i++){

        for( j=3;j<=12;j++){
            ch(URL[pre3],i,j,colour);
            pre3++;
        }
    }


        printf("\n\n"); 
    } 
   
    return 0;
}

//starting ordered_array
int * orderd_array(unsigned char * arr){
    static unsigned int final_arr[133];
    int size = strlen((const char*)arr);
    unsigned int first_ch =50 +size;       //getting the 1st character
    final_arr[0]=first_ch;
    int i,k,z,increment;

    if((3<size)&&(size<=20)){   //for the small version of QR
        unsigned char filter_arr1_small[25]={0};
        strcpy((char*)filter_arr1_small,(const char*)arr);      //getting a copy of arr

        k=0;
        for(i=size;i<23;i++){  //repeating the 'arr' array until the end of filter_arr1_small
               filter_arr1_small[i]= arr[k];
               k+=1;
               if(k==size){
                k=0;
               }
        }
       
        unsigned char filter_arr2_small[25]={0};
        strcpy((char*)filter_arr2_small,(const char*)filter_arr1_small);  //getting a copy of filter_arr1_small
  
        increment = 0;
        for(i=0;i<23;i++){      //incrementing of char is done
            if( (i!=0) && (i%size==0) ){
                increment++;
            }
            filter_arr2_small[i]=filter_arr1_small[i]+increment; 
        }
        
        z=0;
        unsigned char rev_small[25]={0};
        for(i=22;i>size-1;i--){     //reversing the filter_arr2_small until the index is 'size-1'
                    rev_small[z]=filter_arr2_small[i];
                    z++;
                    }

         strcat((char*)arr,(const char*)rev_small);      //combine the reversed array to 'arr'
         
         for(i=0;arr[i]!='\0';i++){          //getting values from arr to final array
                final_arr[i+1]=(int)arr[i];
            }

    }
    else if( (size>20)&&(size<=120) ){      //large version
        unsigned char filter_arr1[133]={0};
        strcpy((char*)filter_arr1,(const char*)arr);        //gettina a copy of 'arr'
     
        k=0;
        for(i=size;i<131;i++){      //repeating the 'arr' array until the end of filter_arr1_small
               filter_arr1[i]= arr[k];
               k+=1;
               if(k==size){
                k=0;
               }
        }
       
        unsigned char filter_arr2[133]={0};
        strcpy((char*)filter_arr2,(const char*)filter_arr1);       //getting a copy of filter_arr1
   
        increment = 0;
        for(i=0;i<131;i++){     //incrementing of char values is done
            if( (i!=0) && (i%size==0) ){
                increment++;
            }
            filter_arr2[i]=filter_arr1[i]+increment;
        }
        
        z=0;
        unsigned char rev[133]={0};
        for(i=130;i>size-1;i--){        //reversing the filter_arr2_small until the index is 'size-1'
                    rev[z]=filter_arr2[i];
                    z++;
                    }        
        strcat((char*)arr,(const char*)rev);        //combine reversed array to 'arr'
        
        for(i=0;arr[i]!='\0';i++){              //getting values from arr to  final array   
                final_arr[i+1]=(int)arr[i];
            }
 
    }
  return (int*)final_arr;      //returnning final array
}

//function for box
void box(){
    printf("\x1b[47m  \x1b[0m");        //print 2 white spaces
}

//function for black
void black(int col){
    if(col == 1){
    	printf("\x1b[40m  \x1b[0m");    //print 2 black spaces
    }
    else if(col==2){
    	printf("\x1b[41m  \x1b[0m");    //2 red spaces
    }
    else if(col==3){
    	printf("\x1b[42m  \x1b[0m");    //2 green spaces
    }
    else if(col==4){
   	printf("\x1b[43m  \x1b[0m");        //2 yellow space
    }
    else if(col==5){
    	printf("\x1b[44m  \x1b[0m");    //2 blue spaces
    }
    else if(col==6){
    	printf("\x1b[45m  \x1b[0m");    //2 magenta spaces
    }
    else if(col==7){
    	printf("\x1b[46m  \x1b[0m");    //2 cyan spaces
    }

}

void ch(unsigned char letter,int row ,int col,int colour){
    
    int i;
    int bin_array[9]={0};
    for(i =8;i>=0;i--){    //i=8 because we consider about 9 bits
        bin_array[8-i] = (letter>>i) & 1;
    }

    printf("\x1b[%i;%iH",3*(row-1)+2,(col-1)*6+3); //getting the cursor to the 1st row of the character
    //printing the 1st row
    for(i = 0 ;i<3;i++){        
        if(bin_array[i]==0){
            box();      //printing white box
        }
        else{
            black(colour);      //printing coloured box
        }
    }
  
    printf("\n");
    printf("\x1b[%i;%iH",3*(row-1)+3,(col-1)*6+3);  //getting the cursor to the 2nd row of the character
    //printing the 2nd row
    for(i = 0 ;i<3;i++){
        if(bin_array[i+3]==0){
            box();
        }
        else{
            black(colour);
        }
    }
    printf("\n");
    printf("\x1b[%i;%iH",3*(row-1)+4,(col-1)*6+3);  //getting the cursor to the 3rd row of the character
    //printing the 3rd row
    for(i = 0 ;i<3;i++){
        if(bin_array[i+6]==0){
            box();
        }
        else{
            black(colour);
        }
    }
    printf("\n");
   
}

void position(int start_row, int start_col,int colour){
    printf("\x1b[%i;%iH",3*start_row-1,start_col*6-3);  //getting the cursor to the the start

    //printing the position identification box

    for(int i=0;i<6;i++){
        black(colour);
    }
    printf("\x1b[%i;%iH",3*start_row-1+1,start_col*6-3);
    black(colour); box(); box(); box(); box(); black(colour);
    printf("\x1b[%i;%iH",3*start_row-1+2,start_col*6-3);
    black(colour); box();black(colour); black(colour); box(); black(colour);
    printf("\x1b[%i;%iH",3*start_row-1+3,start_col*6-3);
    black(colour); box();black(colour); black(colour); box(); black(colour);
    printf("\x1b[%i;%iH",3*start_row-1+4,start_col*6-3);
    black(colour); box(); box(); box(); box(); black(colour);
    printf("\x1b[%i;%iH",3*start_row-1+5,start_col*6-3);
    for(int i=0;i<6;i++){
        black(colour);
    }

}
