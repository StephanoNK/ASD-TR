#include <stdio.h>
#include <stdlib.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <string.h>
#include <conio.h>

void loading(),login(), menu_admin(), menu_utama();
//weadfsdfaewfe
struct mobil{
    char ID[5], nama[100], warna[30];
    int tahun;
    long harga;
    struct mobil* prev;
    struct mobil* next;
};
struct mobil *mobil = NULL;

int main(){
    system("color F0");
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    loading();
    menu_utama();
    return 0;
}

void loading() {
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t     SEDANG LODING, MOHON BERSABAR");
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t");
	for (int i = 0; i <= 1325000000; i++) {
		if (i % 25000000 == 0) {
			printf("█");
		}
	}
	printf("\n\n\t\t\t\t\t\tLOADING TELAH SELESAI");
	_getch();
}

void menu_utama(){
    int pilihan;
    system("cls");
    while (pilihan != 3){
        printf("\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t**********************************\n");
        printf("\t\t\t\t\t**    Kelompok Mobil Mobilan    **\n");
        printf("\t\t\t\t\t**********************************\n");
        printf("\n\n");
        printf("\t\t\t\t\t\t1. Pilih Mobil\n");
        printf("\t\t\t\t\t\t2. Menu Admin\n");
        printf("\t\t\t\t\t\t3. Exit\n");
        printf("\n\t\t\t\t\t\tPilih Menu : ");
        scanf("%i", &pilihan);
        while (getchar() != '\n');

        if (pilihan == 1){
            printf("belum ada menu");
        }
        else if (pilihan == 2){
            login();
        }
    }
}

int attempt = 0;
void login(){
	system("cls");
	int index = 0;
	char user[] = "admin", pw[] = "admin";
	char userinput[50], pwinput[50], c;
	printf("\n\n\n\n\n");
	printf("\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
		"\t\t\t\t░░\t██╗      ██████╗  ██████╗ ██╗███╗   ██╗\t     ░░\n"
		"\t\t\t\t░░\t██║     ██╔═══██╗██╔════╝ ██║████╗  ██║\t     ░░\n"
		"\t\t\t\t░░\t██║     ██║   ██║██║  ███╗██║██╔██╗ ██║\t     ░░\n"
		"\t\t\t\t░░\t██║     ██║   ██║██║   ██║██║██║╚██╗██║\t     ░░\n"
		"\t\t\t\t░░\t███████╗╚██████╔╝╚██████╔╝██║██║ ╚████║\t     ░░\n"
		"\t\t\t\t░░\t╚══════╝ ╚═════╝  ╚═════╝ ╚═╝╚═╝  ╚═══╝\t     ░░\n"
		"\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
	printf("\n\n\n\n");
	printf("\t\t\t\tUsername: ");
	fgets(userinput, sizeof(userinput), stdin);
	userinput[strlen(userinput) - 1] = '\0';
	printf("\t\t\t\tPassword: ");
	while ((c = _getch()) != 13) {
		if (index < 0)
			index = 0;
		if (c == 8 && index > 0) {
			printf("\b \b");
			index--;
			continue;
		}
		if (c == -32) {
			_getch();
			continue;
		}
		if (c >= 32 && c <= 126) {
			pwinput[index] = c;
			index++;
			printf("*");
		}
	}
	pwinput[index] = '\0';
	if (strcmp(userinput, user) == 0 && strcmp(pwinput, pw) == 0) {
		printf("\n\n\n\n\t\t\t\t\t\t   Login berhasil");
		getch();
		menu_admin();

	}
	else {
		attempt++;
		printf("\n\n\t\t\t\tUSERNAME ATAU PASSWORD SALAH (%d/3)", attempt);
		_getch();
		if (attempt == 3) {
			printf("\n\t\t\t\tTERLALU BANYAK KESALAHAN LOGIN");
			_getch();
			exit(0);
		}
		login();
	}
}

void menu_admin(){
    int pilihan;
    system("cls");
    while (pilihan != 6){
        printf("\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t**********************************\n");
        printf("\t\t\t\t\t**       MENU DEALER MOBIL      **\n");
        printf("\t\t\t\t\t**********************************\n");
        printf("\n");
        printf("\t\t\t\t\t\t1. Tambah unit mobil \n");
        printf("\t\t\t\t\t\t2. Edit unit mobil\n");
        printf("\t\t\t\t\t\t3. Hapus unit mobil\n");
        printf("\t\t\t\t\t\t4. Lihat daftar unit mobil\n");
        printf("\t\t\t\t\t\t5. Search unit mobil\n");
        printf("\t\t\t\t\t\t6. Keluar\n");
        printf("\n\t\t\t\t\t\tPilih Menu : ");
        scanf("%i", &pilihan);
        while (getchar() != '\n');

        if (pilihan == 1){
            return;
        }
        else if (pilihan == 2){
            return;
        }
        else if (pilihan == 3){
            return;
        }
        else if (pilihan == 4){
            return;
        }
        else if (pilihan == 5){
            return;
        }
        else if (pilihan == 6){
            exit(0);
        }

    }
}

