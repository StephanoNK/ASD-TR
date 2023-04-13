#include <stdio.h>
#include <stdlib.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <pthread.h>
#include <time.h>

void loading(), login(), menu_admin(), menu_utama(), create(), UwU(), edit();
void read(), delete(), pilih_mobil(), history();

char riwayat[50][50];
int counter = 0;
int rahasia = 0;
pthread_t thread;

struct tm *syst;
time_t t;


struct mobil {
	char ID[8], merk[50], nama[100], warna[30];
	int tahun;
	long long harga;
	struct mobil* prev;
	struct mobil* next;
};
struct mobil* head = NULL;

int main() {
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
		if (i == 4) printf("\033[1B");
		if (i == 8) printf("\033[1B");
		if (i == 44) printf("\033[1A");
		if (i == 48) printf("\033[1A");
		Sleep(50);
	}
	printf("\n\n\t\t\t\t\t\tLOADING TELAH SELESAI");
	_getch();
}

void menu_utama() {
	int pilihan;
	while (pilihan != 3) {
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t**********************************\n");
		printf("\t\t\t\t\t**    Kelompok Mobil Mobilan    **\n");
		printf("\t\t\t\t\t**********************************\n");
		printf("\n\n");
		printf("\t\t\t\t\t\t1. Pilih Mobil\n");
		printf("\t\t\t\t\t\t2. Menu Admin\n");
		printf("\t\t\t\t\t\t3. Exit\n");
		printf("\t\t\t\t\t\t4. ???\n");
		printf("\n\t\t\t\t\t\tPilih Menu : ");
		scanf("%i", &pilihan);
		while (getchar() != '\n');

		if (pilihan == 1) {
			printf("belum ada menu");
		}
		else if (pilihan == 2) {
			login();
		}
		else if (pilihan == 3) {
			exit(0);
		}
		else if (pilihan == 4) {
			if (rahasia == 1) {
				rahasia = 0;
				pthread_join(thread, NULL);
				continue;
			}
			rahasia = 1;
			if (pthread_create(&thread, NULL, UwU, NULL)) {
				fprintf(stderr, "Error creating thread\n");
				continue;
			}
		}
	}

}

int attempt = 0;
void login() {
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
	fflush(stdin);
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

void menu_admin() {
	system("color 0F");
	int pilihan;
	while (pilihan != 6) {
		system("cls");
		printf("\n\n\n\n\n\n\n");
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
		printf("\t\t\t\t\t\t7. History\n");
		printf("\n\t\t\t\t\t\tPilih Menu : ");
		scanf("%i", &pilihan);
		while (getchar() != '\n');

		if (pilihan == 1) {
			create();
		}
		else if (pilihan == 2) {
			edit();
			getch();
		}
		else if (pilihan == 3) {
			delete();
		}
		else if (pilihan == 4) {
			read();
			getch();
		}
		else if (pilihan == 5) {
			search();
			getch();
		}
		else if (pilihan == 6) {
			system("color F0");
			return;
		}
		else if(pilihan == 7){
            history();
		}
	}
}

void search() {
	system("cls");
	char find[30];
	int found = 0;

	struct mobil* temp;
	temp = head;

	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t**********************************\n");
	printf("\t\t\t\t\t**       MENU DEALER MOBIL      **\n");
	printf("\t\t\t\t\t**********************************\n");
	printf("\n");
	printf("\n\t\t\t\t   Masukkan nama mobil yang ingin dicari: ");
	scanf("%s", find);
	printf("\n\t\t\t\t\t  Anda akan mencari %s\n\n", find);
	getch();
	if (temp == NULL) {
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tList kosong\n");
	}
	else {
		while (temp != NULL) {
			if (strcmp(temp->nama, find) == 0) {
				printf("\n\n\n\n\n\n\t\t\t\t\t\t\tMobil ditemukan");
                getch();
				found = 1;
			}
			temp = temp->next;
		}
		if (found == 0) {
			printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tMobil tidak ditemukan");
		}

		found = 0;
		printf("\n\t\t\t\t\t\tSearch Finished");
	}

}


long long inputangka() {
	int index = 0;
	char c;
	char pwinput[100];
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
		if (c >= 48 && c <= 57) {
			pwinput[index] = c;
			index++;
			printf("%c", c);
		}
	}
	pwinput[index] = '\0';
	long long angka = atoll(pwinput);
	return angka;
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
	printf("\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t**********************************\n");
	printf("\t\t\t\t\t**       MENU TAMBAH MOBIL      **\n");
	printf("\t\t\t\t\t**********************************\n");
	printf("\n");
	printf("\n\t\t\t\t\tMasukkan Merk Mobil\t: ");
	scanf("%[^\n]s", &ptr->merk);
	while (getchar() != '\n');
	printf("\n\t\t\t\t\tMasukkan Nama Mobil\t: ");
	scanf("%[^\n]s", &ptr->nama);
	while (getchar() != '\n');
	printf("\n\t\t\t\t\tMasukkan Warna Mobil\t: ");
	scanf("%[^\n]s", &ptr->warna);
	while (getchar() != '\n');
	printf("\n\t\t\t\t\tMasukkan Tahun Mobil\t: ");
	ptr->tahun = (int)inputangka();
	printf("\n\n\t\t\t\t\tMasukkan Harga Mobil\t: ");
	ptr->harga = inputangka();
	sprintf(ptr->ID, "%.2s%.2s%.1s%d", ptr->merk, ptr->nama, ptr->warna, ptr->tahun % 100);
	printf("\n\n\n\n\t\t\t\t\t   Mobil Berhasil Ditambahkan!");

    t = time(NULL);
    syst = localtime(&t);
	sprintf(riwayat[counter],"Admin telah MENAMBAHKAN mobil dengan ID : %s, pada tanggal %s", ptr->ID, asctime(syst));
	counter+=2;

	getch();
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

void read() {
	system("cls");
	struct mobil* ptr;
	int posisi = 0;
	ptr = head;
	printf("\n");
	printf("\t╔═════════╦════════════════╦══════════════════╦══════════════╦═══════════╦═════════════════════╗\n");
	printf("\t║   ID    ║      Merk      ║       Nama       ║     Warna    ║   Tahun   ║        Harga        ║\n");
	printf("\t╠═════════╬════════════════╬══════════════════╬══════════════╬═══════════╬═════════════════════╣\n");
	while (ptr != NULL) {
		printf("\t║         ║                ║                  ║              ║           ║                     ║\n");
		ptr = ptr->next;
		posisi++;
	}
	printf("\t╚═════════╩════════════════╩══════════════════╩══════════════╩═══════════╩═════════════════════╝\n");
	printf("\033[%dA", posisi + 1);
	ptr = head;
	while (ptr != NULL) {
		printf("\t\t\b\b\b\b\b\b%s\n", ptr->ID);
		printf("\033[1A");
		printf("\t\t\b\b\b\b\b\b\t\t\b\b\b\b%s\n", ptr->merk);
		printf("\033[1A");
		printf("\t\t\b\b\b\b\b\b\t\t\b\b\b\b\t\t\t\b\b\b%s\n", ptr->nama);
		printf("\033[1A");
		printf("\t\t\t\t\t\t\t%s\n", ptr->warna);
		printf("\033[1A");
		printf("\t\t\t\t\t\t\t\t\t\b%d\n", ptr->tahun);
		printf("\033[1A");
		printf("\t\t\t\t\t\t\t\t\t\t\t\b\b\b\b\b%lld\n", ptr->harga);
		ptr = ptr->next;
	}
}

void UwU() {
	char warna[16] = { 'A', 'B', 'C', 'D', 'E', 'F', '0', '1', '2','3','4','5','6','7','8','9' };
	srand(time(NULL));
	char commandwarna[20];
	while (rahasia == 1) {
		Sleep(1000);
		char warna1 = warna[rand() % 16];
		char warna2 = warna[rand() % 16];
		sprintf(commandwarna, "color %c%c", warna1, warna2);
		system(commandwarna);
	}
	system("color F0");
	return NULL;


}

void edit() {
	system("cls");
	char find[30];
	int found = 0;
	struct mobil* temp;
	temp = head;

	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t**********************************\n");
	printf("\t\t\t\t\t**       MENU EDIT MOBIL      **\n");
	printf("\t\t\t\t\t**********************************\n");
	printf("\n");
	read();
	printf("\n\t\t\t\t    Masukkan ID mobil yang ingin dicari: ");
	scanf("%s", &find);
	while (getchar() != '\n');
	printf("\n\t\t\t\t    Anda mengupdate data mobil dengan id %s\n\n", find);

	t = time(NULL);
    syst = localtime(&t);
	sprintf(riwayat[counter],"Admin telah MENGEDIT mobil dengan ID : %s, pada tanggal %s", temp->ID, asctime(syst));
	counter+=2;

	getch();
	system("cls");
	if (temp == NULL) {
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tList kosong\n");
	}
	else {
		while (temp != NULL) {
			if (strcmp(temp->ID, find) == 0) {
                printf("\n\n\n\n\n\n\n");
                printf("\t\t\t\t\t**********************************\n");
                printf("\t\t\t\t\t**       MENU EDIT MOBIL      **\n");
                printf("\t\t\t\t\t**********************************\n");
                printf("\n");
				printf("\n\t\t\t\t\t\t Mobil ditemukan\n");
                printf("\n\t\t\t\t\t   Silahkan update date mobil\n");
				printf("\n\t\t\t\t\tMasukkan Merk Mobil: ");
				scanf("%[^\n]s", &temp->merk);
				while (getchar() != '\n');
				printf("\n\t\t\t\t\tMasukkan Nama Mobil: ");
				scanf("%[^\n]s", &temp->nama);
				while (getchar() != '\n');
				printf("\n\t\t\t\t\tMasukkan Warna Mobil: ");
				scanf("%[^\n]s", &temp->warna);
				while (getchar() != '\n');
				printf("\n\t\t\t\t\tMasukkan Tahun Mobil: ");
				temp->tahun = (int)inputangka();
				printf("\n");
				printf("\n\t\t\t\t\tMasukkan Harga Mobil: ");
				temp->harga = inputangka();
				found = 1;
			}
			temp = temp->next;
		}
		if (found == 0){
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tMobil tidak ditemukan");
            return;
		}

	}

}

void pilih_mobil(){
    char find[30];
	int found = 0;
	int jumlah;

	struct mobil* temp;
	temp = head;

    read();

    printf("\n\t\t\t\t   Masukkan pesanan : ");
	scanf("%s", find);
	if (temp == NULL) {
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tList kosong\n");
	}
	else {
		while (temp != NULL) {
			if (strcmp(temp->ID, find) == 0) {
				printf("\n\n\n\n\n\n\t\t\t\t\t\tMobil yang dipilih : %s", &temp->nama);
				printf("\n\n\n\n\n\n\t\t\t\t\t\tJumlah pesanan : ");
                jumlah = inputangka();
                getch();
				found = 1;
			}
			temp = temp->next;
		}
		if (found == 0) {
			printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tMobil tidak ditemukan");
		}

		found = 0;
		printf("\n\t\t\t\t\t\tSearch Finished");
	}
}

void delete() {
	if (head == NULL) {
		printf("List kosong!");
		getch();
		return;
	}
	read();
	char IDhapus[10];
	int posisi = 0;
	struct mobil* ptr, * temp;
	printf("\n\n\t\tKetik ID yang akan dihapus: ");
	scanf("%[^\n]s", &IDhapus);
	while (getchar() != '\n');
	ptr = head;
	while (ptr != NULL) {
		if (ptr->next == NULL && ptr->prev == NULL && strcmp(IDhapus, ptr->ID) == 0) {
			head = NULL;
			t = time(NULL);
            syst = localtime(&t);
            sprintf(riwayat[counter],"Admin telah MENGHAPUS mobil dengan ID : %s, pada tanggal %s", ptr->ID, asctime(syst));
            counter+=2;
			free(ptr);
			printf("\n\t\tMobil dengan ID %s berhasil dihapus!", IDhapus);
			getch();
			return;
		}
		if (ptr->next == NULL && ptr->prev != NULL && strcmp(IDhapus, ptr->ID) == 0) {
			temp = ptr->prev;
			temp->next = NULL;
			t = time(NULL);
            syst = localtime(&t);
            sprintf(riwayat[counter],"Admin telah MENGHAPUS mobil dengan ID : %s, pada tanggal %s", ptr->ID, asctime(syst));
            counter+=2;
			free(ptr);
			printf("\n\t\tMobil dengan ID %s berhasil dihapus!", IDhapus);
			getch();
			return;
		}
		if (ptr->next != NULL && ptr->prev == NULL && strcmp(IDhapus, ptr->ID) == 0) {
			temp = ptr->next;
			temp->prev = NULL;
			t = time(NULL);
            syst = localtime(&t);
            sprintf(riwayat[counter],"Admin telah MENGHAPUS mobil dengan ID : %s, pada tanggal %s", ptr->ID, asctime(syst));
            counter+=2;
			free(ptr);
			printf("\n\t\tMobil dengan ID %s berhasil dihapus!", IDhapus);
			getch();
			return;
		}
		if (strcmp(IDhapus, ptr->ID) == 0) {
			struct mobil* temp2;
			temp = ptr->prev;
			temp2 = ptr->next;
			temp->next = temp2;
			temp2->prev = temp;
			t = time(NULL);
            syst = localtime(&t);
            sprintf(riwayat[counter],"Admin telah MENGHAPUS mobil dengan ID : %s, pada tanggal %s", ptr->ID, asctime(syst));
            counter+=2;
			free(ptr);
			printf("\n\t\tMobil dengan ID %s berhasil dihapus!", IDhapus);
			getch();
			return;
		}
		ptr = ptr->next;
	}
	printf("\n\t\tID tidak ditemukan!");
	getch();
}

void history(){
    system("cls");

    for(int i=0; i<counter; i+=2){
        printf("\n\n\n\t\t%s", riwayat[i]);
    }
    getch();
}
