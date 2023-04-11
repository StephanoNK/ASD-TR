#include <stdio.h>
#include <stdlib.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <string.h>
#include <conio.h>

void loading(),login(), menu_admin(), menu_utama(), create();

struct mobil{
    char ID[7], merk[50], nama[100], warna[30];
    int tahun;
    long harga;
    struct mobil* prev;
    struct mobil* next;
};
struct mobil *head = NULL;

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
	for (int i = 0; i <= 53; i++) {
		printf("█");
		if(i == 4) printf("\033[1B");
		if(i == 8) printf("\033[1B");
		if(i == 44) printf("\033[1A");
		if(i == 48) printf("\033[1A");
		Sleep(50);
	}
	printf("\n\n\t\t\t\t\t\tLOADING TELAH SELESAI");
	_getch();
}

void menu_utama(){
    int pilihan;
    while (pilihan != 3){
		system("cls");
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
    while (pilihan != 6){
		system("cls");
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

void create() {
	system("cls");
	struct mobil* ptr, * temp;
	ptr = (struct mobil*)malloc(sizeof(struct mobil));
	if (ptr == NULL) {
		printf("MEMORY FULL!");
		getch();
		return;
	}
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t**********************************\n");
	printf("\t\t\t\t\t**       MENU TAMBAH MOBIL      **\n");
	printf("\t\t\t\t\t**********************************\n");
	printf("\n");
	printf("\n\t\t\t\t\tMasukkan Merk Mobil: ");
	scanf("%[^\n]s", &ptr->merk);
	while (getchar() != '\n');
	printf("\n\t\t\t\t\tMasukkan Nama Mobil: ");
	scanf("%[^\n]s", &ptr->nama);
	while (getchar() != '\n');
	printf("\n\t\t\t\t\tMasukkan Warna Mobil: ");
	scanf("%[^\n]s", &ptr->warna);
	while (getchar() != '\n');
	printf("\n\t\t\t\t\tMasukkan Tahun Mobil: ");
	scanf("%d", &ptr->tahun);
	while (getchar() != '\n');
	printf("\n\t\t\t\t\tMasukkan Harga Mobil: ");
	scanf("%ld", &ptr->harga);
	while (getchar() != '\n');
	sprintf(ptr->ID, "%.2s%.2s%.1s%d", ptr->merk, ptr->nama, ptr->warna, ptr->tahun % 100);
	ptr->next = NULL;
	if (head == NULL) {
		ptr->next = head;
		ptr->prev = NULL;
		head = ptr;
		return;
	}
	temp = head;
	while (temp->next != NULL) temp = temp->next;
	ptr->prev = temp;
	temp->next = ptr;
}