#include <stdio.h>
#include <stdlib.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <pthread.h>

void loading(), login(), menu_admin(), menu_utama(), create(), UwU();
void read();
int rahasia = 0;
pthread_t thread;

struct mobil {
	char ID[8], merk[60], nama[100], warna[30];
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
		printf("\n\t\t\t\t\t\tPilih Menu : ");
		scanf("%i", &pilihan);
		while (getchar() != '\n');

		if (pilihan == 1) {
			create();
		}
		else if (pilihan == 2) {
			return;
		}
		else if (pilihan == 3) {
			return;
		}
		else if (pilihan == 4) {
			read();
		}
		else if (pilihan == 5) {
			search();
			getch();
		}
		else if (pilihan == 6) {
			system("color F0");
			return;
		}
	}
}

void search() {
	system("cls");
	char find[30];
	struct mobil* temp;
	temp = head;

	printf("Masukkan nama mobil yang ingin dicari: ");
	scanf("%s", &find);
	printf("Anda akan mencari %s\n\n", find);
	getch();
	if (temp == NULL) {
		printf("List Kosong\n");
	}
	else {
		while (temp != NULL) {
			if (strcmp(temp->nama, find) == 0) {
				printf("Mobil ditemukan\n");
				temp = temp->next;
			}
			else {
				printf("Mobil tidak ditemukan\n");
				return;
			}
		}
	}

	getch();
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
	char test[50];
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
		printf("\t\t\b\b\b\b\b\b%s\t\t\b\b\b\b\b\b\b\b\b\b\b\b%s\t\t\b\b\b%s\t\t%s\t\t\b%d\t\t\b\b\b\b\b%lld\n", ptr->ID, ptr->merk, ptr->nama, ptr->warna, ptr->tahun, ptr->harga);
		ptr = ptr->next;
	}
	getch();
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