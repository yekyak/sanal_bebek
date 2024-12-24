#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // sleep fonksiyonu icin
#include <stdbool.h> // bilgileri yazdirirken orta zorluk derecesindeki iki yeni fonksiyonu almak icin
#include <time.h>    // time fonksiyonu icin

// salyangoz (sanal bebek) ASCII gorseli
void art()
{
    printf("\x1b[36m"); // konsol yazi rengini turkuaz yapar
    printf("    .----.   @   @\n");
    printf("   / .-\"-.`.  \\v/\n");
    printf("   | | '\\ \\\\_/  )\n");
    printf(" ,-\\ `-.' /.'  /\n");
    printf("'---`----'----'\n");
    printf("\x1b[m"); // konsol yazi rengini varsayilana dondurur
}

// olu salyangoz ASCII gorseli
void art2()
{
    printf("\x1b[31m"); // konsol yazi rengini turkuaz yapar
    printf("    .----.   X   X\n");
    printf("   / .-\"-.`.  \\v/\n");
    printf("   | | '\\ \\\\_/  )\n");
    printf(" ,-\\ `-.' /.'  /\n");
    printf("'---`----'----'\n");
    printf("\x1b[m"); // konsol yazi rengini varsayilana dondurur
}

// bebegin verilerini tutan struct
typedef struct
{
    int yas;
    float tokluk;
    float uyku;
    float sevgi;
    float hijyen;
    float tuvalet;
    float saglik;
    float sosyallik;
} sanal_bebek;

typedef struct
{
    float tokluk;
    float uyku;
    float sevgi;
    float hijyen;
    float tuvalet;
    float saglik;
    float sosyallik;
} temp_data;

// ilk degerlerin atandigi fonksiyon
void ilk_degerler(sanal_bebek *bebek)
{
    bebek->yas = 0;
    bebek->tokluk = 5;
    bebek->uyku = 5;
    bebek->sevgi = 5;
    bebek->hijyen = 5;
    bebek->tuvalet = 5;
    bebek->saglik = 5;
    bebek->sosyallik = 5;
}

void temp_degerler(sanal_bebek *bebek, temp_data *temp)
{
    temp->tokluk = bebek->tokluk;
    temp->uyku = bebek->uyku;
    temp->sevgi = bebek->sevgi;
    temp->hijyen = bebek->hijyen;
    temp->tuvalet = bebek->tuvalet;
    temp->saglik = bebek->saglik;
    temp->sosyallik = bebek->sosyallik;
}

// tokluk ihtiyacini gidermek icin kullanilan fonksiyon
void yemek(sanal_bebek *bebek)
{
    char secim;
    // yanlis deger girildigi takdirde tekrar soracak
    while (1)
    {
        printf("1. Makarna yedir\n2. Elma puresi yedir\n3. Su icir\n");
        printf("Seciminizi yapin (1, 2, 3): ");
        scanf("%c", &secim);
        while (getchar() != '\n'); // tampondaki gecerli degerden sonra gelen yaziyi temizlemek icin (1! gibi)
        if (secim == '1' || secim == '2' || secim == '3')
        {
            break;
        }
        else
        {
            printf("\x1b[31mGecersiz secim! Lutfen 1, 2 ya da 3 giriniz.\x1b[m\n");
            sleep(2); // 2sn bekle
        }
    }
    printf("\x1b[32m"); // yesil renk kodu
    if (secim == '1')
    {
        bebek->tokluk += 3;
        bebek->uyku += 1;
        bebek->sevgi -= 1;
        bebek->hijyen -= 2;
        bebek->tuvalet += 1;
        bebek->saglik += 1;
        printf("Salyangozun toklugu 3 birim artmistir.\n\n");
    }
    else if (secim == '2')
    {
        bebek->tokluk += 2;
        bebek->uyku += 1;
        bebek->sevgi -= 1;
        bebek->hijyen -= 1;
        bebek->tuvalet += 1;
        bebek->saglik += 1;
        printf("Salyangozun toklugu 2 birim artmistir.\n\n");
    }
    else if (secim == '3')
    {
        bebek->tokluk += 1;
        bebek->uyku += 1;
        bebek->sevgi -= 1;
        bebek->tuvalet += 2;
        printf("Salyangozun toklugu 1 birim artmistir.\n\n");
    }
}

// hijyen ihtiyacini gidermek icin kullanilan fonksiyon
void hijyen(sanal_bebek *bebek)
{
    char secim;
    // yanlis deger girildigi takdirde tekrar soracak
    while (1)
    {
        printf("1. Banyo yaptir\n2. Ellerini yika\n3. Mendille temizle\n");
        printf("Seciminizi yapin (1, 2, 3): ");
        scanf("%c", &secim);
        while (getchar() != '\n'); // tampondaki gecerli degerden sonra gelen yaziyi temizlemek icin (1! gibi)
        if (secim == '1' || secim == '2' || secim == '3')
        {
            break;
        }
        else
        {
            printf("\x1b[31mGecersiz secim! Lutfen 1, 2 ya da 3 giriniz.\x1b[m\n");
            sleep(2); // 2sn bekle
        }
    }
    printf("\x1b[32m");
    if (secim == '1')
    {
        bebek->tokluk -= 1;
        bebek->uyku -= 1;
        bebek->hijyen += 5;
        bebek->tuvalet += 1;
        bebek->saglik += 3;
        bebek->sosyallik -= 1;
        printf("Salyangozun hijyen ihtiyaci 5 birim artmistir.\n\n");
    }
    else if (secim == '2')
    {
        bebek->uyku -= 1;
        bebek->hijyen += 3;
        bebek->tuvalet += 1;
        bebek->saglik += 2;
        bebek->sosyallik -= 1;
        printf("Salyangozun hijyen ihtiyaci 3 birim artmistir.\n\n");
    }
    else if (secim == '3')
    {
        bebek->uyku -= 1;
        bebek->hijyen += 2;
        bebek->tuvalet += 1;
        bebek->saglik += 1;
        printf("Salyangozun hijyen ihtiyaci 2 birim artmistir.\n\n");
    }
}

// sevgi ihtiyacini gidermek icin kullanilan fonksiyon
void sevgi(sanal_bebek *bebek)
{
    char secim;
    // yanlis deger girildigi takdirde tekrar soracak
    while (1)
    {
        printf("1. Masal anlat\n2. Opucuk ver\n3. Saril\n");
        printf("Seciminizi yapin (1, 2, 3): ");
        scanf("%c", &secim);
        while (getchar() != '\n'); // tampondaki gecerli degerden sonra gelen yaziyi temizlemek icin (1! gibi)
        if (secim == '1' || secim == '2' || secim == '3')
        {
            break;
        }
        else
        {
            printf("\x1b[31mGecersiz secim! Lutfen 1, 2 ya da 3 giriniz.\x1b[m\n");
            sleep(2); // 2sn bekle
        }
    }
    printf("\x1b[32m");
    if (secim == '1')
    {
        bebek->tokluk -= 1;
        bebek->uyku += 2;
        bebek->sevgi += 1;
        bebek->tuvalet += 1;
        bebek->sosyallik += 1;
        printf("Salyangozun sevgi ihtiyaci 1 birim artmistir.\n\n");
    }
    else if (secim == '2')
    {
        bebek->uyku += 1;
        bebek->sevgi += 2;
        bebek->tuvalet += 1;
        printf("Salyangozun sevgi ihtiyaci 2 birim artmistir.\n\n");
    }
    else if (secim == '3')
    {
        bebek->uyku += 1;
        bebek->sevgi += 3;
        bebek->tuvalet += 1;
        printf("Salyangozun sevgi ihtiyaci 3 birim artmistir.\n\n");
    }
}

// uyku ihtiyacini gidermek icin kullanilan fonksiyon
void uyku(sanal_bebek *bebek)
{
    char secim;
    // yanlis deger girildigi takdirde tekrar soracak
    while (1)
    {
        printf("1. Yataga gotur\n2. Ninni soyle\n3. Isigi kapat\n");
        printf("Seciminizi yapin (1, 2, 3): ");
        scanf("%c", &secim);
        while (getchar() != '\n'); // tampondaki gecerli degerden sonra gelen yaziyi temizlemek icin (1! gibi)
        if (secim == '1' || secim == '2' || secim == '3')
        {
            break;
        }
        else
        {
            printf("\x1b[31mGecersiz secim! Lutfen 1, 2 ya da 3 giriniz.\x1b[m\n");
            sleep(2); // 2sn bekle
        }
    }
    printf("\x1b[32m");
    if (secim == '1')
    {
        bebek->tokluk -= 1;
        bebek->uyku -= 3;
        bebek->hijyen -= 1;
        bebek->tuvalet += 1;
        bebek->sosyallik -= 1;
        printf("Salyangozun uykusu 3 birim azalmistir.\n\n");
    }
    else if (secim == '2')
    {
        bebek->tokluk -= 1;
        bebek->uyku -= 5;
        bebek->sevgi += 1;
        bebek->hijyen -= 1;
        bebek->tuvalet += 1;
        printf("Salyangozun uykusu 5 birim azalmistir.\n\n");
    }
    else if (secim == '3')
    {
        bebek->tokluk -= 1;
        bebek->uyku -= 2;
        bebek->sevgi -= 1;
        bebek->hijyen -= 1;
        bebek->tuvalet += 1;
        bebek->saglik -= 1;
        bebek->sosyallik -= 1;
        printf("Salyangozun uykusu 2 birim azalmistir.\n\n");
    }
}

// tuvalet ihtiyacini gidermek icin kullanilan fonksiyon
void tuvalet(sanal_bebek *bebek)
{
    char secim;
    // yanlis deger girildigi takdirde tekrar soracak
    while (1)
    {
        printf("1. Tuvalete gotur\n2. Bez degistir\n3. Kayisili mama yedir\n");
        printf("Seciminizi yapin (1, 2, 3): ");
        scanf("%c", &secim);
        while (getchar() != '\n'); // tampondaki gecerli degerden sonra gelen yaziyi temizlemek icin (1! gibi)
        if (secim == '1' || secim == '2' || secim == '3')
        {
            break;
        }
        else
        {
            printf("\x1b[31mGecersiz secim! Lutfen 1, 2 ya da 3 giriniz.\x1b[m\n");
            sleep(2); // 2sn bekle
        }
    }
    printf("\x1b[32m");
    if (secim == '1')
    {
        bebek->tokluk -= 1;
        bebek->uyku += 1;
        bebek->hijyen -= 1;
        bebek->tuvalet -= 5;
        bebek->saglik -= 1;
        bebek->sosyallik -= 1;
        printf("Salyangozun tuvalet ihtiyaci 5 birim azalmistir.\n\n");
    }
    else if (secim == '2')
    {
        bebek->tokluk -= 1;
        bebek->uyku += 1;
        bebek->hijyen -= 1;
        bebek->tuvalet -= 4;
        bebek->saglik -= 1;
        bebek->sosyallik -= 1;
        printf("Salyangozun tuvalet ihtiyaci 4 birim azalmistir.\n\n");
    }
    else if (secim == '3')
    {
        bebek->tokluk += 1;
        bebek->uyku += 1;
        bebek->sevgi -= 1;
        bebek->hijyen -= 1;
        bebek->tuvalet -= 2;
        printf("Salyangozun tuvalet ihtiyaci 2 birim azalmistir.\n\n");
    }
}

// orta zorluk icin saglik fonksiyonu (1)
void saglik(sanal_bebek *bebek)
{
    char secim;
    // yanlis deger girildigi takdirde tekrar soracak
    while (1)
    {
        printf("1. Igne yaptir\n2. Calpol icir\n3. Doktora gotur\n");
        printf("Seciminizi yapin (1, 2, 3): ");
        scanf("%c", &secim);
        while (getchar() != '\n'); // tampondaki gecerli degerden sonra gelen yaziyi temizlemek icin (1! gibi)
        if (secim == '1' || secim == '2' || secim == '3')
        {
            break;
        }
        else
        {
            printf("\x1b[31mGecersiz secim! Lutfen 1, 2 ya da 3 giriniz.\x1b[m\n");
            sleep(2); // 2sn bekle
        }
    }
    printf("\x1b[32m");
    if (secim == '1')
    {
        bebek->sevgi -= 2;
        bebek->saglik += 3;
        printf("Salyangozun saglik ihtiyaci 3 birim artmistir.\n\n");
    }
    else if (secim == '2')
    {
        bebek->sevgi += 1;
        bebek->tuvalet -= 1;
        bebek->saglik += 2;
        printf("Salyangozun saglik ihtiyaci 2 birim artmistir.\n\n");
    }
    else if (secim == '3')
    {
        bebek->uyku += 1;
        bebek->sevgi -= 1;
        bebek->tuvalet -= 1;
        bebek->saglik += 4;
        printf("Salyangozun saglik ihtiyaci 4 birim artmistir.\n\n");
    }
}

// orta zorluk icin sosyallik fonksiyonu (2)
void sosyallik(sanal_bebek *bebek)
{
    char secim;
    // yanlis deger girildigi takdirde tekrar soracak
    while (1)
    {
        printf("1. Parka gotur\n2. Arkadaslariyla oynat\n3. Sarki soyle\n");
        printf("Seciminizi yapin (1, 2, 3): ");
        scanf("%c", &secim);
        while (getchar() != '\n'); // tampondaki gecerli degerden sonra gelen yaziyi temizlemek icin (1! gibi)
        if (secim == '1' || secim == '2' || secim == '3')
        {
            break;
        }
        else
        {
            printf("\x1b[31mGecersiz secim! Lutfen 1, 2 ya da 3 giriniz.\x1b[m\n");
            sleep(2); // 2sn bekle
        }
    }
    printf("\x1b[32m");
    if (secim == '1')
    {
        bebek->tokluk -= 1;
        bebek->uyku += 1;
        bebek->sevgi += 1;
        bebek->hijyen -= 1;
        bebek->tuvalet += 1;
        bebek->saglik -= 1;
        bebek->sosyallik += 2;
        printf("Salyangozun sosyallik ihtiyaci 2 birim artmistir.\n\n");
    }
    else if (secim == '2')
    {
        bebek->tokluk -= 1;
        bebek->uyku += 1;
        bebek->sevgi += 2;
        bebek->hijyen -= 1;
        bebek->tuvalet += 1;
        bebek->saglik -= 1;
        bebek->sosyallik += 3;
        printf("Salyangozun sosyallik ihtiyaci 3 birim artmistir.\n\n");
    }
    else if (secim == '3')
    {
        bebek->tokluk -= 1;
        bebek->uyku += 1;
        bebek->sevgi += 1;
        bebek->sosyallik += 1;
        printf("Salyangozun sosyallik ihtiyaci 1 birim artmistir.\n\n");
    }
}
// cikis islemini rahat kullannmak icin global bir degisken
int puan = 0;

// bebek ihtiyac bilgilerini ekrana yazdiran fonksiyon
void bilgileri_yazdir(sanal_bebek *bebek, bool orta)
{
    // bebegin ASCII gorselinin oldugu fonksiyonu cagirir
    art();
    printf("Tokluk = %.2f\nUyku = %.2f\nSevgi = %.2f\nHijyen = %.2f\nTuvalet = %.2f\n",
           bebek->tokluk, bebek->uyku, bebek->sevgi, bebek->hijyen, bebek->tuvalet);

    if (orta)
    {
        printf("Saglik = %.2f\nSosyallik = %.2f\n\n\x1b[35mYas: %d\x1b[m", bebek->saglik, bebek->sosyallik, bebek->yas);
    }
}

// bebek ihtiyaclarini karsilamak icin secenek sunan fonksiyon
void ihtiyac_menu(sanal_bebek *bebek, bool orta)
{
    char tercih;
    printf("\n---Ihtiyac Menu---\n");
    if (orta)
    {
        printf("1. Yemek Ver\n2. Temizlik Yap\n3. Sevgi Ver\n4. Uyuma\n5. Tuvalet\n6. Saglik\n7. Eglence\n0. Cikis\n");
    }
    else
    {
        printf("1. Yemek Ver\n2. Temizlik Yap\n3. Sevgi Ver\n4. Uyuma\n5. Tuvalet\n0. Cikis\n");
    }
    printf("Seciminizi yapin: ");
    scanf("%c", &tercih);
    while (getchar() != '\n'); // tampondaki gecerli degerden sonra gelen yaziyi temizlemek icin (1! gibi)
    printf("\n");

    if (tercih == '1')
    {
        yemek(bebek);
        puan++;
    }
    else if (tercih == '2')
    {
        hijyen(bebek);
        puan++;
    }
    else if (tercih == '3')
    {
        sevgi(bebek);
        puan++;
    }
    else if (tercih == '4')
    {
        uyku(bebek);
        puan++;
    }
    else if (tercih == '5')
    {
        tuvalet(bebek);
        puan++;
    }
    else if (tercih == '0')
    {
        printf("\x1b[33mOyundan cikiliyor...\x1b[m\n");
        sleep(3);
        system("cls");
        printf("Oyuncunun puani = %d", puan);
        exit(0); // programi sonlandirir
    }
    else if (orta)
    {
        if (tercih == '6')
        {
            saglik(bebek);
            puan++;
        }
        else if (tercih == '7')
        {
            sosyallik(bebek);
            puan++;
        }
    }
    else
    {
        printf("\x1b[31mGecerli bir deger giriniz!\x1b[m");
    }
}

// alt ve ust sinirlarin gecilmemesini saglayan fonksiyon
void sinir_kontrol(sanal_bebek *bebek)
{
    if (bebek->tokluk >= 10)
    {
        printf("\x1b[31mSalyangozun tokluk seviyesi 10'u gecti! Daha fazla besleme.\x1b[m\n\n");
        bebek->tokluk = 10;
    }
    if (bebek->sevgi >= 10)
    {
        printf("\x1b[31mSalyangozun sevgi seviyesi 10'u gecti! Daha fazla sevgiye ihtiyaci yok.\x1b[m\n\n");
        bebek->sevgi = 10;
    }
    if (bebek->hijyen >= 10)
    {
        printf("\x1b[31mSalyangozun hijyen seviyesi 10'u gecti! Salyangoz zaten temiz.\x1b[m\n\n");
        bebek->hijyen = 10;
    }
    if (bebek->uyku <= 0)
    {
        printf("\x1b[31mSalyangozun uyku seviyesi 0. Uykusu yok.\x1b[m\n\n");
        bebek->uyku = 0;
    }
    if (bebek->tuvalet <= 0)
    {
        printf("\x1b[31mSalyangozun tuvalet seviyesi 0. Tuvaleti yok.\x1b[m\n\n");
        bebek->tuvalet = 0;
    }
    if (bebek->saglik >= 10)
    {
        printf("\x1b[31mSalyangozun tuvalet 10'u gecti! Gayet saglikli.\x1b[m\n\n");
        bebek->saglik = 10;
    }
    if (bebek->sosyallik >= 10)
    {
        printf("\x1b[31mSalyangozun tuvalet 10'u gecti! Sosyal pili bitmis.\x1b[m\n\n");
        bebek->sosyallik = 10;
    }
    sleep(3);
    system("cls");
}

// kritik seviyelerin tutuldugu fonksiyon
void kritik_seviye(sanal_bebek *bebek)
{
    if (bebek->tokluk <= 2)
    {
        printf("\x1b[31mSalyangozun tokluk seviyesi 2'nin altina dustu! Beslemelisin.\x1b[m\n\n");
    }
    if (bebek->sevgi <= 2)
    {
        printf("\x1b[31mSalyangozun sevgi seviyesi 2'nin altina dustu! Biraz sevgi goster.\x1b[m\n\n");
    }
    if (bebek->hijyen <= 2)
    {
        printf("\x1b[31mSalyangozun hijyen seviyesi 2'nin altina dustu! Temizlik zamani.\x1b[m\n\n");
    }
    if (bebek->uyku >= 8)
    {
        printf("\x1b[31mSalyangozun uyku seviyesi 8'i gecti! Uyku vakti.\x1b[m\n\n");
    }
    if (bebek->tuvalet >= 8)
    {
        printf("\x1b[31mSalyangozun tuvalet seviyesi 8'i gecti! Tuvaleeeett!!\x1b[m\n\n");
    }
    if (bebek->saglik <= 2)
    {
        printf("\x1b[31mSalyangozun tuvalet seviyesi 8'i gecti! Doktora goturmen lazim.\x1b[m\n\n");
    }
    if (bebek->sosyallik <= 2)
    {
        printf("\x1b[31mSalyangozun tuvalet seviyesi 8'i gecti! Arkadaslariyla vakit gecirmek istiyor.\x1b[m\n\n");
    }
    sleep(3);
    system("cls");
}

// rastgele duygu durumunu belirleyen fonksiyon
char *duygu_durumu(sanal_bebek *bebek)
{
    srand(time(NULL));         // her seferinde farklı bir baslangic degeri
    int sayi = rand() % 9 + 1; // rastgele sayi uretir (1, 2, 3, 4, 5, 6, 7, 8, 9)
    bebek->sevgi = sayi;

    char *M = "Mutlu";
    char *N = "Normal";
    char *U = "Uzgun";
    char *duygu;

    if (sayi < 5)
    {
        duygu = "Uzgun";
    }
    else if (sayi > 7)
    {
        duygu = "Mutlu";
    }
    else
    {
        duygu = "Normal";
    }

    return duygu;
}
// ruh hali degisikliklerini ayarlayan fonksiyon
void ruh_hali(sanal_bebek *bebek, temp_data *temp, char *duygu)
{
    float tokluk, uyku, sevgi, hijyen, tuvalet, saglik, sosyallik;

    if (strcmp(duygu, "Uzgun") == 0)
    {
        tokluk = (temp->tokluk - bebek->tokluk) * (-1.2);
        uyku = (temp->uyku - bebek->uyku) * (-1.2);
        sevgi = (temp->sevgi - bebek->sevgi) * (-1.2);
        hijyen = (temp->hijyen - bebek->hijyen) * (-1.2);
        tuvalet = (temp->tuvalet - bebek->tuvalet) * (-1.2);
        saglik = (temp->saglik - bebek->saglik) * (-1.2);
        sosyallik = (temp->sosyallik - bebek->sosyallik) * (-1.2);
    }
    else if (strcmp(duygu, "Mutlu") == 0)
    {
        tokluk = (temp->tokluk - bebek->tokluk) * (-0.2);
        uyku = (temp->uyku - bebek->uyku) * (-0.2);
        sevgi = (temp->sevgi - bebek->sevgi) * (-0.2);
        hijyen = (temp->hijyen - bebek->hijyen) * (-0.2);
        tuvalet = (temp->tuvalet - bebek->tuvalet) * (-0.2);
        saglik = (temp->saglik - bebek->saglik) * (-0.2);
        sosyallik = (temp->sosyallik - bebek->sosyallik) * (-0.2);
    }
    else if (strcmp(duygu, "Normal") == 0)
    {
        return;
    }
    
    bebek->tokluk = temp->tokluk + tokluk;
    bebek->uyku = temp->uyku + uyku;
    bebek->sevgi = temp->sevgi + sevgi;
    bebek->hijyen = temp->hijyen + hijyen;
    bebek->tuvalet = temp->tuvalet + tuvalet;
    bebek->saglik = temp->saglik + saglik;
    bebek->sosyallik = temp->sosyallik + sosyallik;
}

// kolay oyun modu
void kolay_mod(sanal_bebek *bebek)
{
    while (1)
    {
        bilgileri_yazdir(bebek, false);
        ihtiyac_menu(bebek, false);
        sleep(3);         // 3sn duraklar
        printf("\x1b[m"); // konsol rengini varsayilana ayarlar
        system("cls");
        sleep(2);

        if (bebek->tokluk <= 0 || bebek->sevgi <= 0 || bebek->hijyen <= 0 || bebek->uyku >= 10 || bebek->tuvalet >= 10)
        {
            art2();
            printf("\x1b\n[31mSalyangoz olmustur!\n\x1b[m");
            printf("\nOyuncunun puani = %d", puan);
            break;
        }
        sinir_kontrol(bebek); // ust ve alt sinirlari belirler (0 ve 10)
    }
}

// orta zorluk oyun modu
void orta_mod(sanal_bebek *bebek)
{
    int counter = 0; // yasi arttirmak icin sayac
    while (1)
    {
        bilgileri_yazdir(bebek, true);
        ihtiyac_menu(bebek, true);
        sleep(3);         // 3sn duraklar
        printf("\x1b[m"); // konsol rengini varsayilana ayarlar
        system("cls");

        if (bebek->tokluk <= 0 || bebek->sevgi <= 0 || bebek->hijyen <= 0 || bebek->uyku >= 10 || bebek->tuvalet >= 10 || bebek->saglik <= 0 || bebek->sosyallik <= 0)
        {
            art2();
            printf("\x1b\n[31mSalyangoz olmustur!\n\x1b[m");
            printf("\nOyuncunun puani = %d", puan);
            break;
        }

        sinir_kontrol(bebek); // ust ve alt sinirlari belirler (0 ve 10)
        kritik_seviye(bebek); // bilgiler kritik seviyeye gelirse kullaniciya bilgi verir
        counter++;
        // her 2 islemde yasin bir artmasi icin
        if (counter % 2 == 0)
        {
            bebek->yas++;
        }
    }
}

// zor oyun modu
void zor_mod(sanal_bebek *bebek)
{
    int counter = 0; // yasi arttirmak icin sayac
    char *days[] = {"\x1b[33mGUNDUZ\x1b[m", "\x1b[34mGECE\x1b[m"};
    char *day = days[0];
    char *duygu = duygu_durumu(bebek);
    temp_data temp;
    temp_data *temp_ptr = &temp;
    temp_degerler(bebek, temp_ptr);

    while (1)
    {
        bilgileri_yazdir(bebek, true);
        printf("\n\x1b[32mDuygu durumu: %s\x1b[m", duygu); // mevcut duygu durumunu yazdirir
        printf("\n%s", day);                               // gunduz gece dongusu
        ihtiyac_menu(bebek, true);
        ruh_hali(bebek, temp_ptr, duygu);
        sleep(3);         // 3sn duraklar
        printf("\x1b[m"); // konsol rengini varsayilana ayarlar
        system("cls");

        if (bebek->tokluk <= 0 || bebek->sevgi <= 0 || bebek->hijyen <= 0 || bebek->uyku >= 10 || bebek->tuvalet >= 10 || bebek->saglik <= 0 || bebek->sosyallik <= 0)
        {
            art2();
            printf("\x1b\n[31mSalyangoz olmustur!\n\x1b[m");
            printf("\nOyuncunun puani = %d", puan);
            break;
        }

        sinir_kontrol(bebek); // ust ve alt sinirlari belirler (0 ve 10)
        kritik_seviye(bebek); // bilgiler kritik seviyeye gelirse kullaniciya bilgi verir

        counter++;
        // her 2 islemde yasin bir artmasi icin
        if (counter % 2 == 0)
        {
            bebek->yas++;
        }
        // her 3 islemde bir gunun degismesi icin
        if (counter % 3 == 0)
        {
            if (day == days[0]) // gunduz ise gece yap
                day = days[1];
            else // gece ise gunduz yap
                day = days[0];
        }
    }
}

int main()
{
    sanal_bebek bebek;
    sanal_bebek *ptr = &bebek;
    char zorluk;

    // ilk degerlerin atanmasi
    ilk_degerler(ptr);

    // karsilama metni
    printf("Sanal bebek uygulamasina hosgeldiniz!\n");
    printf("Oyun baslatiliyor...\n");
    sleep(3);      // 3sn duraklar
    system("cls"); // konsolu temizler

    // oyun dongusu
    while (1)
    {
        printf("Oyun zorlugu seciniz (1-kolay, 2-orta, 3-zor): ");
        scanf("%c", &zorluk);
        while (getchar() != '\n'); // tampondaki gecerli degerden sonra gelen yaziyi temizlemek icin (1! gibi)
        if (zorluk == '1')
        {
            printf("\nKolay oyun modu sectiniz.");
            sleep(2);
            system("cls");
            kolay_mod(ptr);
            break;
        }
        else if (zorluk == '2')
        {
            printf("\nOrta zorluk oyun modu sectiniz.");
            sleep(2);
            system("cls");
            orta_mod(ptr);
            break;
        }
        else if (zorluk == '3')
        {
            printf("\nZor oyun modu sectiniz.");
            sleep(2);
            system("cls");
            zor_mod(ptr);
            break;
        }
        else
        {
            printf("\x1b[31mGecerli bir zorluk giriniz giriniz!\x1b[m\n");
            sleep(2);
            system("cls");
        }
    }
    return 0;
}
