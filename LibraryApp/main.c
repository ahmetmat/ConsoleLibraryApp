#include <stdio.h>

typedef struct { // Grup olarak tanımlama
    int id;
    char bookgenre[50];
    char title[100];
 
} Book;// struct türü


void listBooks(Book books[], int length) {// books[] arrayini ve o arrayını içerisinden hangi uzunluğa kadar olanı istediğini alır.
    printf("\nID\tKitap Türü\t\tKitap Adı\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < length; i++) {
        printf("%-4d\t%-20s\t%-40s\n", books[i].id, books[i].bookgenre, books[i].title);
    }
}

Book findBookById(Book books[], int length, int id) {
    for (int i = 0; i < length; i++) {
        if (books[i].id == id) {
            return books[i];
        }
    }
    
    // Eğer kitap bulunamazsa 'id'si -1 olan bir kitap döndürülür.
    Book emptyBook = {-1, "", ""};
    return emptyBook;
}

int main(void) {
    printf("Oğuzhan Kitabevine hoşgeldiniz!\n");
    
    Book books[10] = {
        {1, "Roman", "Suç ve Ceza"},
        {2, "Roman", "Ezilenler"},
        {3, "Felsefe", "Devlet"},
        {4, "Biyografi", "Steve Jobs"},
        {5, "Biyografi", "Leonardo da Vinci"},
        {6, "Kişisel Gelişim", "Çok Yönlü"},
        {7, "Felsefe", "Sokrates'in Savunması"},
        {8, "Kişisel Gelişim", "İrade Eğitimi"},
        {9, "Girişimcilik", "Google"},
        {10, "Bilgisayar", "C Programlama"}
    };
    
    
    int kitapid, choice, result;
    char onay;
    Book selectedBook;

    do {
        printf("\n1. Kitap Ödünç Al\n2. Kitap teslimi \n3. Çok Okunanlar\n4. Kitapları Listele\n5. Çıkış\n \n Seçiminiz: ");
        result = scanf("%d", &choice);

        // Input buffer'ını temizle.
        while (getchar() != '\n');

        if (result != 1 || (choice < 1 || choice > 5)) {
            // Eğer kullanıcı sayısal olmayan bir giriş yaptıysa veya menü dışında bir seçim yaptıysa.
            printf("Geçersiz seçenek. Lütfen 1 ile 5 arasında bir sayı giriniz.\n");
            continue;
        }

        switch(choice) {
            case 1:
                listBooks(books, 10);
                printf("Hangi Kitabı almak istiyorsunuz? (ID giriniz): ");
                result = scanf("%d", &kitapid);
                
                if(result != 1) {
                    printf("Geçersiz ID. Lütfen bir sayı giriniz.\n");
                    continue;
                }
                
                selectedBook = findBookById(books, 10, kitapid);
                if (selectedBook.id == -1) {
                    printf("Seçilen ID'ye sahip bir kitap bulunamadı.\n");
                    printf("Ana menüye yönlendiriliyorsunuz.\n");

                } else {
                    printf("\nSeçilen Kitap:\nID: %d\nTür: %s\nKitap Adı: %s\nBu kitabı almak istiyor musunuz? (E/H): ",
                           selectedBook.id, selectedBook.bookgenre, selectedBook.title);
                    scanf(" %c", &onay);
                    if(onay == 'E' || onay == 'e') {
                        printf("Tebrikler! '%s' kitabını ödünç aldınız.\n", selectedBook.title);
                        printf("Ana menüye yönlendiriliyorsunuz.\n");

                    } else {
                        printf("Kitap alma işlemi iptal edildi.\n");
                        printf("Ana menüye yönlendiriliyorsunuz.\n");
                    }
                }
                break;
            case 2:
                printf("Hangi kitabınızı teslim etmek istiyorsunuz? id: ");
                result = scanf("%d", &kitapid);
                if (result != 1) {
                    // Eğer kullanıcı sayısal olmayan bir giriş yaptıysa.
                    printf("Lütfen geçerli bir kitap ID'si giriniz.\n");
                    printf("Ana menüye yönlendiriliyorsunuz.\n");

                    continue;
                }
                if(kitapid<=10 && kitapid>=0){
                    selectedBook = findBookById(books, 10, kitapid);
                    printf("Tebrikler! '%s' adlı kitabınız teslim ettiniz.\n", selectedBook.title);
                    printf("Ana menüye yönlendiriliyorsunuz.\n");

                }
                else
                {
                    printf("Seçilen ID'ye sahip bir kitap bulunamadı.\n");
                    printf("Ana menüye yönlendiriliyorsunuz.\n");

                }
                break;
            case 3:
                listBooks(books, 5);
                break;
            case 4:
                listBooks(books, 10); // Kitapları listeleme fonksiyonu çağrılıyor
                break;
            case 5:
                printf("Sağlıklı günler, iyi okumalar...\n");

                printf("Sistemden çıkılıyor...\n");
                break;
            default:
                printf("Geçersiz seçenek. Lütfen 1 ile 5 arasında bir sayı giriniz.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

