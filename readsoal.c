#include<stdio.h>
#include<string.h>
int main(){
	char user[100];
	int pilihMenu;
    
    head();
    printf("1. Mulai Permainan \n");
	printf("2. Aturan Permainan \n");
	printf("3. Lihat sekor \n");
	printf("4. Keluar \n");
	printf("Pilih: ");
	scanf("%d", &pilihMenu);
	switch(pilihMenu){
		case 1:
			printf("Masukkan Namamu: ");
			scanf("%s", &user);
			mulai(user);
			getch();
			main();
			break;
		case 2:
			head();
			aturan();
			break;
		case 3:
			lbd();
			break;
		default:
			system(0);
			break;		
	}
}

int lbd(){
	head();
	char user[100][100];
	char skor[100][100];
	int i=0,a=0;
	FILE *d=fopen("skor.txt","r");
	if(!d){
		printf("tidak ada file");
	}else{
		while(!feof(d)){
			fscanf(d, "%[^.].%[^#]#", &user[i], &skor[i]);
			i++;
			a++;
		}
		fclose(d);
	}
	for(i=0;i<a-1;i++){
		printf("%d. %s = %s\n", i+1, user[i], skor[i]);
	}
	printf("Tekan sembarang untuk kembali");
	getch();
	main();
}

int mulai(char user[100]){
	char soal[20][100];
	char kunci[20][100];
	char jawab[20][100];
	int skor=0;
	int i=0,i2=0;
	int list[20];
	FILE *kc=fopen("kunci.txt", "r");
    if(!kc){
		printf("tidak ada file");
	}else{
		while(!feof(kc)){
			fscanf(kc, "%[^#]#", &kunci[i2]);fflush(stdin);
			i2++;
		} 
		fclose(kc);
	}
    
        FILE *in=fopen("soal.txt","r");
        if(!in){  //cek apakah filenya ada atau tidak
           printf("tidak ada file");
        }else{
        	while(!feof(in)){
              fscanf(in,"%[^#]#", &soal[i]);fflush(stdin);
              i++;
			}
           fclose(in);
        }
        
        for(i=0;i<20;i++){
        	head();
			printf("%s", soal[i]);
			scanf("%s", &jawab[i]);
			if(strcmp(jawab[i], kunci[i]) == 0){
				skor++;
			}else{

			}
			system("cls");
		}
		head();
		printf("Yey, kamu mendapat skor %d\n", skor*5);
		FILE *sp=fopen("skor.txt","a");
		if(!in){
			printf("tidak ada file");
		}else{
			fprintf(sp,"%s.%d#", user,skor*5);
			fclose(sp);
		}
}

int head(){
	system("cls");
	void tengah2(int width, char* s) {
	 int l = strlen(s);
	 int pos = (int)((width - l) / 2);
	 int i;
	 for (i = 0; i < pos; i++) 
	 { 
	 	 printf( " "); 
	 }
	 printf("%s", s); ;
	}
	printf("==SIFAT ALLAH CHALLENGE ONE==\n");
}

int aturan(){
	printf("Soal terdiri atas 20 soal. Terdapat 2 opsi pilihan.\n Pilih Jawaban yang menurut kamu paling tepat.\njawaban benar mendapat skor 5.\nJawaban salah mendapat skor 0.\n\nTekan sembarang untuk kembali\n");
	getch();
	system("cls");
	main();
}