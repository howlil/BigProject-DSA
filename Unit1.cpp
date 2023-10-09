//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include<windows.h>

#include "Unit1.h"

#include "Unit3.h"
 int totStok,susun, n=0;
int ayamI,tahuI,tempeI;
int tahuS,tempeS, dds,phas,phbs,sys;
int pesan1,pesan2,pesan3;
int total_beli, total_harga, bayar,kembalian;
int jumlahPelanggan = 0;
int harga_dada,harga_pahaA, harga_pahaB,harga_sayap, harga_tempe, harga_tahu;
int ddr,phar,phbr,syr,tpr,thr,t_hargar;
AnsiString name,namar,cbb, tgl,var_status;

int totTerjual=0, produksiAyam=0,produksiTp=0,produksiTh=0;
int untungTot=0,untungdd=0,untungsy=0 ,untungpa=0,untungth=0,untungtp=0,unttungpb=0;





struct kasir
{
   AnsiString nama;
   int no;
   int totalHarga;
   int totalBeli;
   int stok;
   int dada;
   int pahaA;
   int pahaB;
   int sayap ;
   int tempe;
   int tahu;
   kasir*next;
   kasir*prev;

};
   kasir*head_stok = NULL;
   kasir* tail_stok = NULL;
   kasir*head = NULL;
   kasir*tail= NULL;
   kasir*header= NULL;
   kasir*footer = NULL;


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
Button10->Enabled=false;
Button1->Enabled=false;
Button12->Enabled=false;
Button18->Enabled=false;
Button2->Enabled=false;
Button16->Enabled=false;
Button17->Enabled=false;
Button4->Enabled=false;
Button5->Enabled=false;
Button3->Enabled=false;
Button6->Enabled=false;
Button7->Enabled=false;
Button9->Enabled=false;
Button8->Enabled=false;
Button14->Enabled=false;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
/*
============kalkulasi untung dan modal ====================

modal :
1 ekor ayam = 60 ribu : 8 potong = 7,5 ribu
1 papan tempe = 12 ribu : 12 potong = 1 ribu
1 loyang tahu = 8 ribu : 8 potong = 1 ribu

untung :
dada = 14k - 7,5k = 6,5k
sayap = 12k - 7,5k = 4,5k
paha atas = 13k - 7,5k = 5,5k
paha bawah - 11k - 7,5k =  3,5k
tahu = 2k-1k = 1k
tempe = 3k -1k = 2k

untungdd = banyak dada * 6,5k dst
modal ayam = banayak potong * 7,5k

*/


            susun =  StrToInt(Edit1->Text);

            if((susun % 4 != 0) || (susun > 13)){
              ShowMessage("Harus kelipatan 4 & kurang sama dari 12");

            }else{

            kasir*stack = new kasir;
            stack->stok = susun;
            stack->next=NULL;
            stack->prev=NULL;

                if(head_stok == NULL){
                    head_stok=stack;
                    tail_stok = stack;
                }else{
                    head_stok->prev=stack;
                    stack->next=head_stok;
                    head_stok=head_stok->prev;
                }


                ListBox1->Items->Clear();
                kasir *tampil= head_stok;
                while(tampil!=NULL){
                    if(tampil->stok > 0){
                        ListBox1->Items->Add(tampil->stok);
                    }
                    tampil=tampil->next;
                }

                ListBox2->Items->Clear();
                kasir *total=head_stok;
                 totStok = 0;
                while(total != NULL){
                    totStok = totStok + total->stok;
                    total = total->next;
                }
                ListBox2->Items->Add(totStok);
              }
                Edit1->Clear();
                Button3->Enabled = true;
                Button16->Enabled = true;
                Button17->Enabled = true;









}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
     kasir*cari ;
                    kasir*pin = head_stok;
                        while(pin !=NULL){
                            cari = pin;
                                while(cari!= NULL){
                                    if(cari->stok > pin->stok){
                                        int temp;
                                        temp = cari->stok;
                                        cari->stok = pin->stok;
                                        pin->stok = temp;
                                    }
                                cari = cari->next;
                                }
                        pin = pin->next;
                        }

                ListBox1->Items->Clear();
                kasir*show = head_stok;
                    while(show != NULL){
                        if(show->stok > 0){
                            ListBox1->Items->Add(show->stok);
                        }
                     show = show->next;
                    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
     kasir*cari ;
                    kasir*pin = head_stok;
                        while(pin !=NULL){
                            cari = pin;
                                while(cari!= NULL){
                                    if(cari->stok < pin->stok){
                                        int temp;
                                        temp = cari->stok;
                                        cari->stok = pin->stok;
                                        pin->stok = temp;
                                    }
                                cari = cari->next;
                                }
                        pin = pin->next;
                        }

                ListBox1->Items->Clear();
                kasir*show = head_stok;
                    while(show != NULL){
                        if(show->stok > 0){
                            ListBox1->Items->Add(show->stok);
                        }
                     show = show->next;
                    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 int cbb3 = ComboBox3->ItemIndex;

     ayamI = StrToInt(Edit2->Text);
     tahuI = StrToInt(Edit3->Text);
     tempeI = StrToInt(Edit4->Text);


        switch(cbb3){
            case 0:
            {
              if(totStok <4){
               ShowMessage("stok kurang");
              }else{
     int sum = ayamI * 4;
     int sumA = sum/4;

            kasir* root = head_stok;
                while (root != NULL) {
                    if (sum > root->stok) {
                        sum = sum - root->stok;
                        root = root->next;
                            if (root != NULL) {
                                root->prev = NULL;
                                head_stok = root;
                                    if (root->next != NULL) {
                                        sum = sum - root->stok;
                                            if (sum <= 0) {
                                                sum = -sum;
                                                root->stok = sum;
                                                sum = 0;
                                            }
                                    }
                            } else {
                                ShowMessage("stok tidak cukup");
                                return;
                            }
                        } else {
                            root->stok = root->stok - sum;
                            sum = 0;
                            break; // keluar dari loop karena sudah selesai memproses
                        }
                }

              ListBox1->Clear();
              kasir *show = head_stok;
              while(show!= NULL) {
                 if(show->stok > 0){
                    ListBox1->Items->Add(show->stok);
                 }
                show = show->next;
              }

              ListBox2->Clear();
              totStok = 0;
              kasir*total = new kasir;
              total = head_stok;
              while(total != NULL){
                totStok += total->stok;
                total = total->next;
              }
              ListBox2->Items->Add(totStok);


                dds  += sumA;
                phas += sumA;
                phbs += sumA;
                sys  += sumA;
              ListBox3->Clear();
              ListBox4->Clear();
              ListBox5->Clear();
              ListBox6->Clear();

              ListBox3->Items->Add(sys);
              ListBox4->Items->Add(dds);
              ListBox5->Items->Add(phbs);
              ListBox6->Items->Add(phas);

                ListBox8->Clear();
                ListBox7->Clear();
                tahuS += tahuI;
                tempeS += tempeI;
                ListBox8->Items->Add(tahuS);
                ListBox7->Items->Add(tempeS);
                Button5->Enabled = true;
                Button1->Enabled = true;
           }
           break;
         }


           case 1 :
           {
              if(totStok <4){
               ShowMessage("stok kurang");
              }else{
     int sum = ayamI * 8;
     int sumA = sum/4;
            kasir* root = head_stok;
                while (root != NULL) {
                    if (sum > root->stok) {
                        sum = sum - root->stok;
                        root = root->next;
                            if (root != NULL) {
                                root->prev = NULL;
                                head_stok = root;
                                    if (root->next != NULL) {
                                        sum = sum - root->stok;
                                            if (sum <= 0) {
                                                sum = -sum;
                                                root->stok = sum;
                                                sum = 0;
                                            }
                                    }
                            } else {
                                ShowMessage("stok tidak cukup");
                                return;
                            }
                        } else {
                            root->stok = root->stok - sum;
                            sum = 0;
                            break; // keluar dari loop karena sudah selesai memproses
                        }
                }

              ListBox1->Clear();
              kasir *show = head_stok;
              while(show!= NULL) {
                 if(show->stok > 0){
                    ListBox1->Items->Add(show->stok);
                 }
                show = show->next;
              }

              ListBox2->Clear();
              totStok = 0;
              kasir*total = new kasir;
              total = head_stok;
              while(total != NULL){
                totStok += total->stok;
                total = total->next;
              }
              ListBox2->Items->Add(totStok);


                dds  += sumA;
                phas += sumA;
                phbs += sumA;
                sys  += sumA;
              ListBox3->Clear();
              ListBox4->Clear();
              ListBox5->Clear();
              ListBox6->Clear();

              ListBox3->Items->Add(sys);
              ListBox4->Items->Add(dds);
              ListBox5->Items->Add(phbs);
              ListBox6->Items->Add(phas);

                ListBox8->Clear();
                ListBox7->Clear();
                tahuS += tahuI;
                tempeS += tempeI;
                ListBox8->Items->Add(tahuS);
                ListBox7->Items->Add(tempeS);
                Button5->Enabled = true;
                Button1->Enabled = true;
              }
              break;
           }
         case 2 :
         {
              if(totStok <4){
               ShowMessage("stok kurang");
              }else{
     int sum = ayamI *12;
     int sumA = sum/4;
            kasir* root = head_stok;
                while (root != NULL) {
                    if (sum > root->stok) {
                        sum = sum - root->stok;
                        root = root->next;
                            if (root != NULL) {
                                root->prev = NULL;
                                head_stok = root;
                                    if (root->next != NULL) {
                                        sum = sum - root->stok;
                                            if (sum <= 0) {
                                                sum = -sum;
                                                root->stok = sum;
                                                sum = 0;
                                            }
                                    }
                            } else {
                                ShowMessage("stok tidak cukup");
                                return;
                            }
                        } else {
                            root->stok = root->stok - sum;
                            sum = 0;
                            break; // keluar dari loop karena sudah selesai memproses
                        }
                }

              ListBox1->Clear();
              kasir *show = head_stok;
              while(show!= NULL) {
                 if(show->stok > 0){
                    ListBox1->Items->Add(show->stok);
                 }
                show = show->next;
              }

              ListBox2->Clear();
              totStok = 0;
              kasir*total = new kasir;
              total = head_stok;
              while(total != NULL){
                totStok += total->stok;
                total = total->next;
              }
              ListBox2->Items->Add(totStok);


                dds  += sumA;
                phas += sumA;
                phbs += sumA;
                sys  += sumA;
              ListBox3->Clear();
              ListBox4->Clear();
              ListBox5->Clear();
              ListBox6->Clear();

              ListBox3->Items->Add(sys);
              ListBox4->Items->Add(dds);
              ListBox5->Items->Add(phbs);
              ListBox6->Items->Add(phas);

                ListBox8->Clear();
                ListBox7->Clear();
                tahuS += tahuI;
                tempeS += tempeI;
                ListBox8->Items->Add(tahuS);
                ListBox7->Items->Add(tempeS);
                Button5->Enabled = true;
                Button1->Enabled = true;
          }
          break;
        }
      }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  int cbb3 = ComboBox3->ItemIndex;

     ayamI = StrToInt(Edit2->Text);
     tahuI = StrToInt(Edit3->Text);
     tempeI = StrToInt(Edit4->Text);


        switch(cbb3){
            case 0:
            {
              if(totStok <4){
               ShowMessage("stok kurang");
              }else{
     int sum = ayamI * 4;
     int sumA = sum/4;

            kasir* root = head_stok;
                while (root != NULL) {
                    if (sum > root->stok) {
                        sum = sum - root->stok;
                        root = root->next;
                            if (root != NULL) {
                                root->prev = NULL;
                                head_stok = root;
                                    if (root->next != NULL) {
                                        sum = sum - root->stok;
                                            if (sum <= 0) {
                                                sum = -sum;
                                                root->stok = sum;
                                                sum = 0;
                                            }
                                    }
                            } else {
                                ShowMessage("stok tidak cukup");
                                return;
                            }
                        } else {
                            root->stok = root->stok - sum;
                            sum = 0;
                            break; // keluar dari loop karena sudah selesai memproses
                        }
                }

              ListBox1->Clear();
              kasir *show = head_stok;
              while(show!= NULL) {
                 if(show->stok > 0){
                    ListBox1->Items->Add(show->stok);
                 }
                show = show->next;
              }

              ListBox2->Clear();
              totStok = 0;
              kasir*total = new kasir;
              total = head_stok;
              while(total != NULL){
                totStok += total->stok;
                total = total->next;
              }
              ListBox2->Items->Add(totStok);


                dds  += sumA;
                phas += sumA;
                phbs += sumA;
                sys  += sumA;
              ListBox3->Clear();
              ListBox4->Clear();
              ListBox5->Clear();
              ListBox6->Clear();

              ListBox3->Items->Add(sys);
              ListBox4->Items->Add(dds);
              ListBox5->Items->Add(phbs);
              ListBox6->Items->Add(phas);

                ListBox8->Clear();
                ListBox7->Clear();
                tahuS += tahuI;
                tempeS += tempeI;
                ListBox8->Items->Add(tahuS);
                ListBox7->Items->Add(tempeS);
                Button5->Enabled = true;
                Button1->Enabled = true;
           }
           break;
         }


           case 1 :
           {
              if(totStok <4){
               ShowMessage("stok kurang");
              }else{
     int sum = ayamI * 8;
     int sumA = sum/4;
            kasir* root = head_stok;
                while (root != NULL) {
                    if (sum > root->stok) {
                        sum = sum - root->stok;
                        root = root->next;
                            if (root != NULL) {
                                root->prev = NULL;
                                head_stok = root;
                                    if (root->next != NULL) {
                                        sum = sum - root->stok;
                                            if (sum <= 0) {
                                                sum = -sum;
                                                root->stok = sum;
                                                sum = 0;
                                            }
                                    }
                            } else {
                                ShowMessage("stok tidak cukup");
                                return;
                            }
                        } else {
                            root->stok = root->stok - sum;
                            sum = 0;
                            break; // keluar dari loop karena sudah selesai memproses
                        }
                }

              ListBox1->Clear();
              kasir *show = head_stok;
              while(show!= NULL) {
                 if(show->stok > 0){
                    ListBox1->Items->Add(show->stok);
                 }
                show = show->next;
              }

              ListBox2->Clear();
              totStok = 0;
              kasir*total = new kasir;
              total = head_stok;
              while(total != NULL){
                totStok += total->stok;
                total = total->next;
              }
              ListBox2->Items->Add(totStok);


                dds  += sumA;
                phas += sumA;
                phbs += sumA;
                sys  += sumA;
              ListBox3->Clear();
              ListBox4->Clear();
              ListBox5->Clear();
              ListBox6->Clear();

              ListBox3->Items->Add(sys);
              ListBox4->Items->Add(dds);
              ListBox5->Items->Add(phbs);
              ListBox6->Items->Add(phas);

                ListBox8->Clear();
                ListBox7->Clear();
                tahuS += tahuI;
                tempeS += tempeI;
                ListBox8->Items->Add(tahuS);
                ListBox7->Items->Add(tempeS);
                Button5->Enabled = true;
                Button1->Enabled = true;
              }
              break;
           }
         case 2 :
         {
              if(totStok <4){
               ShowMessage("stok kurang");
              }else{
     int sum = ayamI *12;
     int sumA = sum/4;
            kasir* root = head_stok;
                while (root != NULL) {
                    if (sum > root->stok) {
                        sum = sum - root->stok;
                        root = root->next;
                            if (root != NULL) {
                                root->prev = NULL;
                                head_stok = root;
                                    if (root->next != NULL) {
                                        sum = sum - root->stok;
                                            if (sum <= 0) {
                                                sum = -sum;
                                                root->stok = sum;
                                                sum = 0;
                                            }
                                    }
                            } else {
                                ShowMessage("stok tidak cukup");
                                return;
                            }
                        } else {
                            root->stok = root->stok - sum;
                            sum = 0;
                            break; // keluar dari loop karena sudah selesai memproses
                        }
                }

              ListBox1->Clear();
              kasir *show = head_stok;
              while(show!= NULL) {
                 if(show->stok > 0){
                    ListBox1->Items->Add(show->stok);
                 }
                show = show->next;
              }

              ListBox2->Clear();
              totStok = 0;
              kasir*total = new kasir;
              total = head_stok;
              while(total != NULL){
                totStok += total->stok;
                total = total->next;
              }
              ListBox2->Items->Add(totStok);


                dds  += sumA;
                phas += sumA;
                phbs += sumA;
                sys  += sumA;
              ListBox3->Clear();
              ListBox4->Clear();
              ListBox5->Clear();
              ListBox6->Clear();

              ListBox3->Items->Add(sys);
              ListBox4->Items->Add(dds);
              ListBox5->Items->Add(phbs);
              ListBox6->Items->Add(phas);

                ListBox8->Clear();
                ListBox7->Clear();
                tahuS += tahuI;
                tempeS += tempeI;
                ListBox8->Items->Add(tahuS);
                ListBox7->Items->Add(tempeS);
                Button5->Enabled = true;
                Button1->Enabled = true;
          }
          break;
        }
      }


}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
int cbb2 = (ComboBox2->ItemIndex);
  cbb = ComboBox2->Text;
  name = Edit5->Text;
  pesan1= StrToInt(Edit6->Text);
  pesan2= StrToInt(Edit7->Text);
  pesan3= StrToInt(Edit8->Text);
static int count = 0;
count++;


     int jawab;
      jawab = Application->MessageBox("Apakah ada pelanggan berikutnya", "Jika Ya = masuk list antrian Tidak = pesanan diproses", MB_YESNO | MB_ICONQUESTION);
       if (jawab == IDYES)
        {

          ShowMessage("Masuk Antrian Dulu");
                if (ListBox10->Items->Count >= 3 || jawab == IDNO)
                {
                        ShowMessage("Pesanan siap");
                        Button7->Enabled = true;
                }


 switch(cbb2)
  {
    case 0 :
    {
      if(pesan1 <= dds && pesan2 <= tahuS && pesan3 <= tempeS){
        if(Edit7 != "0" && Edit8 != "0"){
        n++;
           dds = dds - pesan1;
           tahuS = tahuS - pesan2;
           tempeS = tempeS - pesan3;
           total_beli = pesan1 + pesan2 + pesan3;

           harga_dada = pesan1* 14000;
           harga_tempe = pesan3* 3000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_dada + harga_tempe + harga_tahu;

           ListBox4->Clear();
           ListBox7->Clear();
           ListBox8->Clear();
           ListBox4->Items->Add(dds);
           ListBox7->Items->Add(tempeS);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->pahaA= 0;
           data->pahaB=0;
           data->sayap=0;
           data->dada = pesan1;
           data->tahu = pesan2;
           data->tempe = pesan3;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

           Button6->Enabled = true;
          
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);
           Button6->Enabled = true;

        }else if( Edit7->Text != "0" && Edit8->Text == "0"){
                n++;
           dds = dds - pesan1;
           tahuS = tahuS - pesan2;
           total_beli = pesan1 + pesan2 ;

           harga_dada = pesan1* 14000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_dada + harga_tahu;

           ListBox4->Clear();
           ListBox8->Clear();
           ListBox4->Items->Add(dds);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->pahaA= 0;
           data->pahaB=0;
           data->sayap=0;
           data->dada = pesan1;
           data->tahu = pesan2;
           data->tempe =0 ;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
           
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text == "0" && Edit8->Text != "0"){
              n++;
           dds = dds - pesan1;
           tempeS = tempeS - pesan3;
           total_beli = pesan1  + pesan3;

           harga_dada = pesan1* 14000;
           harga_tempe = pesan3* 3000;
           total_harga = harga_dada + harga_tempe;

           ListBox4->Clear();
           ListBox7->Clear();
           ListBox4->Items->Add(dds);
           ListBox7->Items->Add(tempeS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->pahaA= 0;
           data->pahaB=0;
           data->sayap=0;
           data->dada = pesan1;
           data->tempe = pesan3;
           data->tahu=0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if(Edit7->Text == "0" && Edit8->Text == "0"){
                 n++;
           dds = dds - pesan1;
           total_beli = pesan1 ;

           harga_dada = pesan1* 14000;
           total_harga = harga_dada ;

           ListBox4->Clear();
           ListBox4->Items->Add(dds);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->pahaA= 0;
           data->pahaB=0;
           data->sayap=0;
           data->dada = pesan1;
           data->tahu =0;
           data->tempe = 0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);
        }

      }else{
        ShowMessage("Isi Stok");
        Button4->Enabled = true;
           jumlahPelanggan ++;

      }
      break;
    }


    case 1 :
    {
      if(pesan1 <= phas && pesan2 <= tahuS && pesan3 <= tempeS){
        if(Edit7 != "0" && Edit8 != "0"){
             n++;
           phas = phas - pesan1;
           tahuS = tahuS - pesan2;
           tempeS = tempeS - pesan3;
           total_beli = pesan1 + pesan2 + pesan3;

           harga_pahaA = pesan1* 13000;
           harga_tempe = pesan3* 3000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_pahaA + harga_tempe + harga_tahu;

           ListBox6->Clear();
           ListBox7->Clear();
           ListBox8->Clear();
           ListBox6->Items->Add(phas);
           ListBox7->Items->Add(tempeS);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->pahaA = pesan1;
           data->pahaB=0;
           data->sayap=0;
           data->dada =0;
           data->tahu = pesan2;
           data->tempe = pesan3;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
          ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text != "0" && Edit8->Text == "0"){
             n++;
           phas = phas - pesan1;
           tahuS = tahuS - pesan2;
           total_beli = pesan1 + pesan2 ;

           harga_pahaA = pesan1* 13000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_pahaA + harga_tahu;

           ListBox6->Clear();
           ListBox8->Clear();
           ListBox6->Items->Add(phas);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->pahaA = pesan1;
           data->pahaB=0;
           data->sayap=0;
           data->dada =0;
           data->tahu = pesan2;
           data->tempe = 0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text == "0" && Edit8->Text != "0"){
             n++;
           phas = phas - pesan1;
           tempeS = tempeS - pesan3;
           total_beli = pesan1  + pesan3;

           harga_pahaA = pesan1* 13000;
           harga_tempe = pesan3* 3000;
           total_harga = harga_pahaA + harga_tempe;

           ListBox6->Clear();
           ListBox7->Clear();
           ListBox6->Items->Add(phas);
           ListBox7->Items->Add(tempeS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->pahaA = pesan1;
           data->tempe = pesan3;
           data->tahu = 0;
           data->pahaB=0;
           data->sayap=0;
           data->dada =0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

            Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
          ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if(Edit7->Text == "0" && Edit8->Text == "0"){
               n++;
           phas = phas - pesan1;
           total_beli = pesan1 ;

           harga_pahaA = pesan1* 13000;
           total_harga = harga_pahaA ;

           ListBox6->Clear();
           ListBox6->Items->Add(phas);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->pahaA = pesan1;
           data->pahaB=0;
           data->sayap=0;
           data->dada =0;
           data->tahu = 0;
           data->tempe =0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);
        }

      }else{
        ShowMessage("Isi Stok");
          jumlahPelanggan ++;
          
      }
      break;
    }


    case 2 :
    {
      if(pesan1 <= phbs && pesan2 <= tahuS && pesan3 <= tempeS){
        if(Edit7 != "0" && Edit8 != "0"){
             n++;
           phbs = phbs - pesan1;
           tahuS = tahuS - pesan2;
           tempeS = tempeS - pesan3;
           total_beli = pesan1 + pesan2 + pesan3;

           harga_pahaB = pesan1* 11000;
           harga_tempe = pesan3* 3000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_pahaB + harga_tempe + harga_tahu;

           ListBox5->Clear();
           ListBox7->Clear();
           ListBox8->Clear();
           ListBox5->Items->Add(phbs);
           ListBox7->Items->Add(tempeS);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->pahaB = pesan1;
           data->pahaA=0;
           data->sayap=0;
           data->dada =0;
           data->no= n;
           data->tahu = pesan2;
           data->tempe = pesan3;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
          ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text != "0" && Edit8->Text == "0"){
               n++;
           phbs = phbs - pesan1;
           tahuS = tahuS - pesan2;
           total_beli = pesan1 + pesan2 ;

           harga_pahaB = pesan1* 11000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_pahaB + harga_tahu;

           ListBox5->Clear();
           ListBox8->Clear();
           ListBox5->Items->Add(phbs);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->pahaA=0;
           data->sayap=0;
           data->dada =0;
           data->pahaB = pesan1;
           data->tahu = pesan2;
           data->tempe=0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text == "0" && Edit8->Text != "0"){
                 n++;
           phbs = phbs - pesan1;
           tempeS = tempeS - pesan3;
           total_beli = pesan1  + pesan3;

           harga_pahaB = pesan1* 11000;
           harga_tempe = pesan3* 3000;
           total_harga = harga_pahaB + harga_tempe;

           ListBox4->Clear();
           ListBox7->Clear();
           ListBox5->Items->Add(phbs);
           ListBox7->Items->Add(tempeS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->pahaB = pesan1;
           data->pahaA=0;
           data->sayap=0;
           data->dada =0;
           data->tahu = 0;
           data->tempe = pesan3;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if(Edit7->Text == "0" && Edit8->Text == "0"){
               n++;
           phbs = phbs - pesan1;
           total_beli = pesan1 ;

           harga_pahaB = pesan1* 11000;
           total_harga = harga_pahaB ;

           ListBox5->Clear();
           ListBox5->Items->Add(phbs);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->pahaB = pesan1;
           data->pahaA=0;
           data->sayap=0;
           data->dada =0;
           data->tempe=0;
           data->tahu = 0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);
        }

      }else{
        ShowMessage("Isi Stok");
            jumlahPelanggan ++;

        Button4->Enabled = true;
      }
      break;
    }


    case 3 :
    {
      if(pesan1 <= sys && pesan2 <= tahuS && pesan3 <= tempeS){
        if(Edit7 != "0" && Edit8 != "0"){
              n++;
           sys = sys - pesan1;
           tahuS = tahuS - pesan2;
           tempeS = tempeS - pesan3;
           total_beli = pesan1 + pesan2 + pesan3;

           harga_sayap = pesan1* 12000;
           harga_tempe = pesan3* 3000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_sayap + harga_tempe + harga_tahu;

           ListBox3->Clear();
           ListBox7->Clear();
           ListBox8->Clear();
           ListBox3->Items->Add(sys);
           ListBox7->Items->Add(tempeS);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->sayap = pesan1;
           data->pahaA=0;
           data->pahaB=0;
           data->dada =0;
           data->tahu = pesan2;
           data->tempe = pesan3;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text != "0" && Edit8->Text == "0"){
               n++;
           sys = sys - pesan1;
           tahuS = tahuS - pesan2;
           total_beli = pesan1 + pesan2 ;

           harga_sayap = pesan1* 12000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_sayap + harga_tahu;

           ListBox3->Clear();
           ListBox8->Clear();
           ListBox3->Items->Add(sys);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->sayap = pesan1;
           data->tahu = pesan2;
           data->pahaA=0;
           data->pahaB=0;
           data->dada =0;
           data->tempe=0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

            Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text == "0" && Edit8->Text != "0"){
                n++;
           sys = sys - pesan1;
           tempeS = tempeS - pesan3;
           total_beli = pesan1  + pesan3;

           harga_sayap = pesan1* 12000;
           harga_tempe = pesan3* 3000;
           total_harga = harga_sayap + harga_tempe;

           ListBox3->Clear();
           ListBox7->Clear();
           ListBox3->Items->Add(sys);
           ListBox7->Items->Add(tempeS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->sayap = pesan1;
           data->tempe = pesan3;
           data->pahaA=0;
           data->pahaB=0;
           data->dada =0;
           data->tahu = 0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if(Edit7->Text == "0" && Edit8->Text == "0"){
               n++;
           sys = sys - pesan1;
           total_beli = pesan1 ;

           harga_sayap = pesan1* 12000;
           total_harga = harga_sayap ;

           ListBox3->Clear();
           ListBox3->Items->Add(sys);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->pahaA=0;
           data->pahaB=0;
           data->dada =0;
           data->tempe=0;
           data->tahu = 0;
           data->sayap = pesan1;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

           Button6->Enabled = true;

           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);
        }

      }else{
        ShowMessage("Isi Stok") ;
            jumlahPelanggan ++;

        Button4->Enabled = true;
      }
      break;
    }

  
Button5->Enabled = false;
    }
       }
       else if (ListBox10->Items->Count > 0 &&jawab == IDNO  )
        {
        ShowMessage("baik pesanan anda akan diproses");
           Button7->Enabled = true;

 switch(cbb2)
  {
    case 0 :
    {
      if(pesan1 <= dds && pesan2 <= tahuS && pesan3 <= tempeS){
        if(Edit7 != "0" && Edit8 != "0"){
            n++;
           dds = dds - pesan1;
           tahuS = tahuS - pesan2;
           tempeS = tempeS - pesan3;
           total_beli = pesan1 + pesan2 + pesan3;

           harga_dada = pesan1* 14000;
           harga_tempe = pesan3* 3000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_dada + harga_tempe + harga_tahu;

           ListBox4->Clear();
           ListBox7->Clear();
           ListBox8->Clear();
           ListBox4->Items->Add(dds);
           ListBox7->Items->Add(tempeS);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->pahaA= 0;
           data->pahaB=0;
           data->sayap=0;
           data->dada = pesan1;
           data->tahu = pesan2;
           data->tempe = pesan3;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

           Button6->Enabled = true;
          
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);
           Button6->Enabled = true;

        }else if( Edit7->Text != "0" && Edit8->Text == "0"){
             n++;
           dds = dds - pesan1;
           tahuS = tahuS - pesan2;
           total_beli = pesan1 + pesan2 ;

           harga_dada = pesan1* 14000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_dada + harga_tahu;

           ListBox4->Clear();
           ListBox8->Clear();
           ListBox4->Items->Add(dds);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->pahaA= 0;
           data->pahaB=0;
           data->sayap=0;
           data->dada = pesan1;
           data->tahu = pesan2;
           data->tempe =0 ;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
           
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text == "0" && Edit8->Text != "0"){
              n++;
           dds = dds - pesan1;
           tempeS = tempeS - pesan3;
           total_beli = pesan1  + pesan3;

           harga_dada = pesan1* 14000;
           harga_tempe = pesan3* 3000;
           total_harga = harga_dada + harga_tempe;

           ListBox4->Clear();
           ListBox7->Clear();
           ListBox4->Items->Add(dds);
           ListBox7->Items->Add(tempeS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->pahaA= 0;
           data->pahaB=0;
           data->sayap=0;
           data->dada = pesan1;
           data->tempe = pesan3;
           data->tahu=0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if(Edit7->Text == "0" && Edit8->Text == "0"){
             n++;
           dds = dds - pesan1;
           total_beli = pesan1 ;

           harga_dada = pesan1* 14000;
           total_harga = harga_dada ;

           ListBox4->Clear();
           ListBox4->Items->Add(dds);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->pahaA= 0;
           data->pahaB=0;
           data->sayap=0;
           data->dada = pesan1;
           data->tahu =0;
           data->tempe = 0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);
        }

      }else{
        ShowMessage("Isi Stok");
        Button4->Enabled = true;
           jumlahPelanggan ++;

      }
      break;
    }


    case 1 :
    {
      if(pesan1 <= phas && pesan2 <= tahuS && pesan3 <= tempeS){
        if(Edit7 != "0" && Edit8 != "0"){
            n++;
           phas = phas - pesan1;
           tahuS = tahuS - pesan2;
           tempeS = tempeS - pesan3;
           total_beli = pesan1 + pesan2 + pesan3;

           harga_pahaA = pesan1* 13000;
           harga_tempe = pesan3* 3000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_pahaA + harga_tempe + harga_tahu;

           ListBox6->Clear();
           ListBox7->Clear();
           ListBox8->Clear();
           ListBox6->Items->Add(phas);
           ListBox7->Items->Add(tempeS);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->pahaA = pesan1;
           data->pahaB=0;
           data->sayap=0;
           data->dada =0;
           data->tahu = pesan2;
           data->tempe = pesan3;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
          ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text != "0" && Edit8->Text == "0"){
            n++;
           phas = phas - pesan1;
           tahuS = tahuS - pesan2;
           total_beli = pesan1 + pesan2 ;

           harga_pahaA = pesan1* 13000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_pahaA + harga_tahu;

           ListBox6->Clear();
           ListBox8->Clear();
           ListBox6->Items->Add(phas);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->pahaA = pesan1;
           data->pahaB=0;
           data->sayap=0;
           data->dada =0;
           data->tahu = pesan2;
           data->tempe = 0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text == "0" && Edit8->Text != "0"){
        
           phas = phas - pesan1;
           tempeS = tempeS - pesan3;
           total_beli = pesan1  + pesan3;

           harga_pahaA = pesan1* 13000;
           harga_tempe = pesan3* 3000;
           total_harga = harga_pahaA + harga_tempe;

           ListBox6->Clear();
           ListBox7->Clear();
           ListBox6->Items->Add(phas);
           ListBox7->Items->Add(tempeS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->pahaA = pesan1;
           data->tempe = pesan3;
           data->tahu = 0;
           data->pahaB=0;
           data->sayap=0;
           data->dada =0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
           
            Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
          ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if(Edit7->Text == "0" && Edit8->Text == "0"){
             n++;
           phas = phas - pesan1;
           total_beli = pesan1 ;

           harga_pahaA = pesan1* 13000;
           total_harga = harga_pahaA ;

           ListBox6->Clear();
           ListBox6->Items->Add(phas);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->pahaA = pesan1;
           data->pahaB=0;
           data->sayap=0;
           data->dada =0;
           data->tahu = 0;
           data->tempe =0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);
        }

      }else{
        ShowMessage("Isi Stok");
          jumlahPelanggan ++;
          
      }
      break;
    }


    case 2 :
    {
      if(pesan1 <= phbs && pesan2 <= tahuS && pesan3 <= tempeS){
        if(Edit7 != "0" && Edit8 != "0"){
            n++;
           phbs = phbs - pesan1;
           tahuS = tahuS - pesan2;
           tempeS = tempeS - pesan3;
           total_beli = pesan1 + pesan2 + pesan3;

           harga_pahaB = pesan1* 11000;
           harga_tempe = pesan3* 3000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_pahaB + harga_tempe + harga_tahu;

           ListBox5->Clear();
           ListBox7->Clear();
           ListBox8->Clear();
           ListBox5->Items->Add(phbs);
           ListBox7->Items->Add(tempeS);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->pahaB = pesan1;
           data->pahaA=0;
           data->sayap=0;
           data->dada =0;
           data->no= n;
           data->tahu = pesan2;
           data->tempe = pesan3;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
          ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text != "0" && Edit8->Text == "0"){
             n++;
           phbs = phbs - pesan1;
           tahuS = tahuS - pesan2;
           total_beli = pesan1 + pesan2 ;

           harga_pahaB = pesan1* 11000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_pahaB + harga_tahu;

           ListBox5->Clear();
           ListBox8->Clear();
           ListBox5->Items->Add(phbs);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->pahaA=0;
           data->sayap=0;
           data->dada =0;
           data->pahaB = pesan1;
           data->tahu = pesan2;
           data->tempe=0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text == "0" && Edit8->Text != "0"){
             n++;
           phbs = phbs - pesan1;
           tempeS = tempeS - pesan3;
           total_beli = pesan1  + pesan3;

           harga_pahaB = pesan1* 11000;
           harga_tempe = pesan3* 3000;
           total_harga = harga_pahaB + harga_tempe;

           ListBox4->Clear();
           ListBox7->Clear();
           ListBox5->Items->Add(phbs);
           ListBox7->Items->Add(tempeS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->pahaB = pesan1;
           data->pahaA=0;
           data->sayap=0;
           data->dada =0;
           data->tahu = 0;
           data->tempe = pesan3;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if(Edit7->Text == "0" && Edit8->Text == "0"){
              n++;
           phbs = phbs - pesan1;
           total_beli = pesan1 ;

           harga_pahaB = pesan1* 11000;
           total_harga = harga_pahaB ;

           ListBox5->Clear();
           ListBox5->Items->Add(phbs);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->pahaB = pesan1;
           data->pahaA=0;
           data->sayap=0;
           data->dada =0;
           data->tempe=0;
           data->tahu = 0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);
        }

      }else{
        ShowMessage("Isi Stok");
            jumlahPelanggan ++;

        Button4->Enabled = true;
      }
      break;
    }


    case 3 :
    {
      if(pesan1 <= sys && pesan2 <= tahuS && pesan3 <= tempeS){
        if(Edit7 != "0" && Edit8 != "0"){
              n++;
           sys = sys - pesan1;
           tahuS = tahuS - pesan2;
           tempeS = tempeS - pesan3;
           total_beli = pesan1 + pesan2 + pesan3;

           harga_sayap = pesan1* 12000;
           harga_tempe = pesan3* 3000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_sayap + harga_tempe + harga_tahu;

           ListBox3->Clear();
           ListBox7->Clear();
           ListBox8->Clear();
           ListBox3->Items->Add(sys);
           ListBox7->Items->Add(tempeS);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->sayap = pesan1;
           data->pahaA=0;
           data->pahaB=0;
           data->dada =0;
           data->tahu = pesan2;
           data->tempe = pesan3;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text != "0" && Edit8->Text == "0"){
            n++;
           sys = sys - pesan1;
           tahuS = tahuS - pesan2;
           total_beli = pesan1 + pesan2 ;

           harga_sayap = pesan1* 12000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_sayap + harga_tahu;

           ListBox3->Clear();
           ListBox8->Clear();
           ListBox3->Items->Add(sys);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->sayap = pesan1;
           data->tahu = pesan2;
           data->pahaA=0;
           data->pahaB=0;
           data->dada =0;
           data->tempe=0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
           
            Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text == "0" && Edit8->Text != "0"){
            n++;
           sys = sys - pesan1;
           tempeS = tempeS - pesan3;
           total_beli = pesan1  + pesan3;

           harga_sayap = pesan1* 12000;
           harga_tempe = pesan3* 3000;
           total_harga = harga_sayap + harga_tempe;

           ListBox3->Clear();
           ListBox7->Clear();
           ListBox3->Items->Add(sys);
           ListBox7->Items->Add(tempeS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->sayap = pesan1;
           data->tempe = pesan3;
           data->pahaA=0;
           data->pahaB=0;
           data->dada =0;
           data->tahu = 0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if(Edit7->Text == "0" && Edit8->Text == "0"){
            n++;
           sys = sys - pesan1;
           total_beli = pesan1 ;

           harga_sayap = pesan1* 12000;
           total_harga = harga_sayap ;

           ListBox3->Clear();
           ListBox3->Items->Add(sys);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->pahaA=0;
           data->pahaB=0;
           data->dada =0;
           data->tempe=0;
           data->tahu = 0;
           data->sayap = pesan1;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

           Button6->Enabled = true;
          
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);
        }

      }else{
        ShowMessage("Isi Stok") ;
            jumlahPelanggan ++;

        Button4->Enabled = true;
      }
      break;
    }

Button5->Enabled = false;
    }
        }


        else if (jawab == IDNO && ListBox10->Items->Count == 0)
        {
         ShowMessage("mohon tunggu sebentar");
         Sleep(5000);
            Button7->Enabled = true;


 switch(cbb2)
  {
    case 0 :
    {
      if(pesan1 <= dds && pesan2 <= tahuS && pesan3 <= tempeS){
        if(Edit7 != "0" && Edit8 != "0"){
            n++;
           dds = dds - pesan1;
           tahuS = tahuS - pesan2;
           tempeS = tempeS - pesan3;
           total_beli = pesan1 + pesan2 + pesan3;

           harga_dada = pesan1* 14000;
           harga_tempe = pesan3* 3000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_dada + harga_tempe + harga_tahu;

           ListBox4->Clear();
           ListBox7->Clear();
           ListBox8->Clear();
           ListBox4->Items->Add(dds);
           ListBox7->Items->Add(tempeS);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->pahaA= 0;
           data->pahaB=0;
           data->sayap=0;
           data->dada = pesan1;
           data->tahu = pesan2;
           data->tempe = pesan3;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

           Button6->Enabled = true;
          
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);
           Button6->Enabled = true;

        }else if( Edit7->Text != "0" && Edit8->Text == "0"){
           n++;
           dds = dds - pesan1;
           tahuS = tahuS - pesan2;
           total_beli = pesan1 + pesan2 ;

           harga_dada = pesan1* 14000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_dada + harga_tahu;

           ListBox4->Clear();
           ListBox8->Clear();
           ListBox4->Items->Add(dds);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->pahaA= 0;
           data->pahaB=0;
           data->sayap=0;
           data->dada = pesan1;
           data->tahu = pesan2;
           data->tempe =0 ;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
           
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text == "0" && Edit8->Text != "0"){
            n++;
           dds = dds - pesan1;
           tempeS = tempeS - pesan3;
           total_beli = pesan1  + pesan3;

           harga_dada = pesan1* 14000;
           harga_tempe = pesan3* 3000;
           total_harga = harga_dada + harga_tempe;

           ListBox4->Clear();
           ListBox7->Clear();
           ListBox4->Items->Add(dds);
           ListBox7->Items->Add(tempeS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->pahaA= 0;
           data->pahaB=0;
           data->sayap=0;
           data->dada = pesan1;
           data->tempe = pesan3;
           data->tahu=0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if(Edit7->Text == "0" && Edit8->Text == "0"){
            n++;
           dds = dds - pesan1;
           total_beli = pesan1 ;

           harga_dada = pesan1* 14000;
           total_harga = harga_dada ;

           ListBox4->Clear();
           ListBox4->Items->Add(dds);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->pahaA= 0;
           data->pahaB=0;
           data->sayap=0;
           data->dada = pesan1;
           data->tahu =0;
           data->tempe = 0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);
        }

      }else{
        ShowMessage("Isi Stok");
        Button4->Enabled = true;
           jumlahPelanggan ++;

      }
      break;
    }


    case 1 :
    {
      if(pesan1 <= phas && pesan2 <= tahuS && pesan3 <= tempeS){
        if(Edit7 != "0" && Edit8 != "0"){
           n++;
           phas = phas - pesan1;
           tahuS = tahuS - pesan2;
           tempeS = tempeS - pesan3;
           total_beli = pesan1 + pesan2 + pesan3;

           harga_pahaA = pesan1* 13000;
           harga_tempe = pesan3* 3000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_pahaA + harga_tempe + harga_tahu;

           ListBox6->Clear();
           ListBox7->Clear();
           ListBox8->Clear();
           ListBox6->Items->Add(phas);
           ListBox7->Items->Add(tempeS);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->pahaA = pesan1;
           data->pahaB=0;
           data->sayap=0;
           data->dada =0;
           data->tahu = pesan2;
           data->tempe = pesan3;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
          ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text != "0" && Edit8->Text == "0"){
            n++;
           phas = phas - pesan1;
           tahuS = tahuS - pesan2;
           total_beli = pesan1 + pesan2 ;

           harga_pahaA = pesan1* 13000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_pahaA + harga_tahu;

           ListBox6->Clear();
           ListBox8->Clear();
           ListBox6->Items->Add(phas);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->pahaA = pesan1;
           data->pahaB=0;
           data->sayap=0;
           data->dada =0;
           data->tahu = pesan2;
           data->tempe = 0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text == "0" && Edit8->Text != "0"){
           n++;
           phas = phas - pesan1;
           tempeS = tempeS - pesan3;
           total_beli = pesan1  + pesan3;

           harga_pahaA = pesan1* 13000;
           harga_tempe = pesan3* 3000;
           total_harga = harga_pahaA + harga_tempe;

           ListBox6->Clear();
           ListBox7->Clear();
           ListBox6->Items->Add(phas);
           ListBox7->Items->Add(tempeS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->pahaA = pesan1;
           data->tempe = pesan3;
           data->tahu = 0;
           data->pahaB=0;
           data->sayap=0;
           data->dada =0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
           
            Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
          ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if(Edit7->Text == "0" && Edit8->Text == "0"){
            n++;
           phas = phas - pesan1;
           total_beli = pesan1 ;

           harga_pahaA = pesan1* 13000;
           total_harga = harga_pahaA ;

           ListBox6->Clear();
           ListBox6->Items->Add(phas);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->pahaA = pesan1;
           data->pahaB=0;
           data->sayap=0;
           data->dada =0;
           data->tahu = 0;
           data->tempe =0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);
        }

      }else{
        ShowMessage("Isi Stok");
          jumlahPelanggan ++;
          
      }
      break;
    }


    case 2 :
    {
      if(pesan1 <= phbs && pesan2 <= tahuS && pesan3 <= tempeS){
        if(Edit7 != "0" && Edit8 != "0"){
            n++;
           phbs = phbs - pesan1;
           tahuS = tahuS - pesan2;
           tempeS = tempeS - pesan3;
           total_beli = pesan1 + pesan2 + pesan3;

           harga_pahaB = pesan1* 11000;
           harga_tempe = pesan3* 3000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_pahaB + harga_tempe + harga_tahu;

           ListBox5->Clear();
           ListBox7->Clear();
           ListBox8->Clear();
           ListBox5->Items->Add(phbs);
           ListBox7->Items->Add(tempeS);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->pahaB = pesan1;
           data->pahaA=0;
           data->sayap=0;
           data->dada =0;
           data->no= n;
           data->tahu = pesan2;
           data->tempe = pesan3;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
          ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text != "0" && Edit8->Text == "0"){
            n++;
           phbs = phbs - pesan1;
           tahuS = tahuS - pesan2;
           total_beli = pesan1 + pesan2 ;

           harga_pahaB = pesan1* 11000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_pahaB + harga_tahu;

           ListBox5->Clear();
           ListBox8->Clear();
           ListBox5->Items->Add(phbs);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->pahaA=0;
           data->sayap=0;
           data->dada =0;
           data->pahaB = pesan1;
           data->tahu = pesan2;
           data->tempe=0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text == "0" && Edit8->Text != "0"){
             n++;
           phbs = phbs - pesan1;
           tempeS = tempeS - pesan3;
           total_beli = pesan1  + pesan3;

           harga_pahaB = pesan1* 11000;
           harga_tempe = pesan3* 3000;
           total_harga = harga_pahaB + harga_tempe;

           ListBox4->Clear();
           ListBox7->Clear();
           ListBox5->Items->Add(phbs);
           ListBox7->Items->Add(tempeS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->pahaB = pesan1;
           data->pahaA=0;
           data->sayap=0;
           data->dada =0;
           data->tahu = 0;
           data->tempe = pesan3;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if(Edit7->Text == "0" && Edit8->Text == "0"){
            n++;
           phbs = phbs - pesan1;
           total_beli = pesan1 ;

           harga_pahaB = pesan1* 11000;
           total_harga = harga_pahaB ;

           ListBox5->Clear();
           ListBox5->Items->Add(phbs);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->pahaB = pesan1;
           data->pahaA=0;
           data->sayap=0;
           data->dada =0;
           data->tempe=0;
           data->tahu = 0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);
        }

      }else{
        ShowMessage("Isi Stok");
            jumlahPelanggan ++;

        Button4->Enabled = true;
      }
      break;
    }


    case 3 :
    {
      if(pesan1 <= sys && pesan2 <= tahuS && pesan3 <= tempeS){
        if(Edit7 != "0" && Edit8 != "0"){
            n++;
           sys = sys - pesan1;
           tahuS = tahuS - pesan2;
           tempeS = tempeS - pesan3;
           total_beli = pesan1 + pesan2 + pesan3;

           harga_sayap = pesan1* 12000;
           harga_tempe = pesan3* 3000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_sayap + harga_tempe + harga_tahu;

           ListBox3->Clear();
           ListBox7->Clear();
           ListBox8->Clear();
           ListBox3->Items->Add(sys);
           ListBox7->Items->Add(tempeS);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->sayap = pesan1;
           data->pahaA=0;
           data->pahaB=0;
           data->dada =0;
           data->tahu = pesan2;
           data->tempe = pesan3;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
          
           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text != "0" && Edit8->Text == "0"){
            n++;
           sys = sys - pesan1;
           tahuS = tahuS - pesan2;
           total_beli = pesan1 + pesan2 ;

           harga_sayap = pesan1* 12000;
           harga_tahu = pesan2* 2000;
           total_harga = harga_sayap + harga_tahu;

           ListBox3->Clear();
           ListBox8->Clear();
           ListBox3->Items->Add(sys);
           ListBox8->Items->Add(tahuS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->nama = name;
           data->no= n;
           data->sayap = pesan1;
           data->tahu = pesan2;
           data->pahaA=0;
           data->pahaB=0;
           data->dada =0;
           data->tempe=0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }
           
            Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if( Edit7->Text == "0" && Edit8->Text != "0"){
             n++;
           sys = sys - pesan1;
           tempeS = tempeS - pesan3;
           total_beli = pesan1  + pesan3;

           harga_sayap = pesan1* 12000;
           harga_tempe = pesan3* 3000;
           total_harga = harga_sayap + harga_tempe;

           ListBox3->Clear();
           ListBox7->Clear();
           ListBox3->Items->Add(sys);
           ListBox7->Items->Add(tempeS);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->sayap = pesan1;
           data->tempe = pesan3;
           data->pahaA=0;
           data->pahaB=0;
           data->dada =0;
           data->tahu = 0;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

           Button6->Enabled = true;
           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);

        }else if(Edit7->Text == "0" && Edit8->Text == "0"){
             n++;
           sys = sys - pesan1;
           total_beli = pesan1 ;

           harga_sayap = pesan1* 12000;
           total_harga = harga_sayap ;

           ListBox3->Clear();
           ListBox3->Items->Add(sys);

           kasir*data = new kasir;
           data->next = NULL;
           data->prev = NULL;
           data->no= n;
           data->nama = name;
           data->pahaA=0;
           data->pahaB=0;
           data->dada =0;
           data->tempe=0;
           data->tahu = 0;
           data->sayap = pesan1;
           data->totalBeli=total_beli;
           data->totalHarga= total_harga;

           if(head == NULL){
                head = data;
                tail = data;
           }
           else{
                tail->next = data;
                data->prev = tail;
                tail = data;
           }

           Button6->Enabled = true;

           ListBox10->Items->Add(data->nama);
           ListBox9->Items->Add(data->no);
           ListBox11->Items->Add(data->totalBeli);
           ListBox12->Items->Add(data->totalHarga);
        }

      }else{
        ShowMessage("Isi Stok") ;

        jumlahPelanggan ++;

        Button4->Enabled = true;
      }
      break;
    }
    }
        }
 Button5->Enabled = false;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{


    kasir* first = head;
    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }


    first->next = NULL;
    first->prev = NULL;

    if (header == NULL) {
        header = first;
        footer = first;
    } else {
        footer->next = first;
        first->prev = footer;
        footer = first;
    }

    ListBox9->Clear();
    ListBox10->Clear();
    ListBox11->Clear();
    ListBox12->Clear();
    ListBox13->Clear(); // hapus pengulangan data di ListBox13

    kasir* tampil = head;
    while (tampil != NULL) {
       ListBox10->Items->Add(tampil->nama);
       ListBox11->Items->Add(IntToStr(tampil->totalBeli));
       ListBox12->Items->Add(IntToStr(tampil->totalHarga));
       ListBox9->Items->Add(IntToStr(tampil->no-1));

       tampil = tampil->next;
    }


        // tambahkan data ke ListBox13 setelah ListBox13 dikosongkan
    ListBox13->Clear();
ListBox13->Clear();
ListBox24->Clear(); // Kosongkan ListBox24 juga
ListBox13->Items->Add(IntToStr(header->totalHarga));
ListBox24->Items->Add(header->nama);

kasir* p = header; // Mulai dari node selanjutnya
while (p != NULL) {
ListBox13->Clear();
ListBox24->Clear();
   ListBox13->Items->Add(IntToStr(p->totalHarga));
   ListBox24->Items->Add(p->nama);
   p = p->next; // Pindah ke node selanjutnya
}


    Button8->Enabled = true;
 Button7->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
   int a;
   AnsiString nnew;
   int nno=0;

int recordCount = ADOQuery3->RecordCount;
    a = recordCount + 1;
 int ddnew =   0;
   int synew =  0;
   int panew =   0;
   int pbnew =   0;
   int thnew =  0;
   int tpnew =  0;
   int tHnew =   0;

ADOQuery3->SQL->Clear();
ADOQuery3->SQL->Add("SELECT MAX(no) FROM riwayat_transaksi");
ADOQuery3->Open();

if (!ADOQuery3->Fields->Fields[0]) {
    nno = ADOQuery3->Fields->Fields[0]->AsInteger + 1;
} else {
    nno = 1;
}

ADOQuery3->Close();

bayar = StrToInt(Edit9->Text);
ListBox14->Clear(); // Kosongkan ListBox14 sebelum memulai perhitungan kembalian
kasir* x = header->next; // Mulai dari node selanjutnya
while (x != NULL) {
    if (bayar < x->totalHarga) {
        ShowMessage("Uang kurang");
        return;
    } else {
        kembalian = bayar - x->totalHarga;
        ListBox14->Items->Add(kembalian);
        x = x->next;
    }
}

ListBox15->Clear();
ListBox16->Clear();
ListBox17->Clear();
ListBox18->Clear();
ListBox19->Clear();
ListBox20->Clear();
ListBox21->Clear();
ListBox22->Clear();
ListBox23->Clear();

kasir* tampil = header;
while (tampil != NULL) {
    nno = a;
    nnew = tampil->nama;
    ddnew = tampil->dada;
    synew = tampil->sayap;
    panew = tampil->pahaA;
    pbnew = tampil->pahaB;
    thnew = tampil->tahu;
    tpnew = tampil->tempe;
    tHnew = tampil->totalHarga;

    ListBox15->Items->Add(IntToStr(tampil->no));
    ListBox16->Items->Add(tampil->nama);
    ListBox17->Items->Add(IntToStr(tampil->dada));
    ListBox19->Items->Add(IntToStr(tampil->pahaA));
    ListBox20->Items->Add(IntToStr(tampil->pahaB));
    ListBox21->Items->Add(IntToStr(tampil->sayap));
    ListBox22->Items->Add(IntToStr(tampil->tempe));
    ListBox23->Items->Add(IntToStr(tampil->tahu));
    ListBox18->Items->Add(IntToStr(tampil->totalHarga));

    tampil = tampil->next;
}

Button7->Enabled = true;
Button14->Enabled = true;

ADOQuery3->SQL->Clear();
ADOQuery3->SQL->Add("SELECT COUNT(*) FROM riwayat_transaksi WHERE no = " + IntToStr(nno));
ADOQuery3->Open();

if (ADOQuery3->Fields->Fields[0]->AsInteger > 0) {
    // Nilai no sudah ada, tampilkan pesan kesalahan atau lakukan tindakan lain
    ShowMessage("No sudah terdaftar");
} else {
    // Nilai no belum ada, lanjutkan dengan operasi INSERT
    ADOQuery3->Close();
    ADOQuery3->SQL->Clear();
    ADOQuery3->SQL->Add("INSERT INTO riwayat_transaksi(no, tanggal, nama_pelanggan, dada, paha_atas, paha_bawah, sayap, tahu, tempe, total_harga) "
                       "VALUES ('" + IntToStr(nno) + "','" + DateTimePicker1->Date + "','" + nnew + "','" + IntToStr(ddnew) + "','" + IntToStr(synew) + "','" + IntToStr(panew) + "','" + IntToStr(pbnew) + "','" + IntToStr(thnew) + "','" + IntToStr(tpnew) + "','" + IntToStr(tHnew) + "')");
    ADOQuery3->ExecSQL();
}
ADOQuery3->SQL->Clear();
ADOQuery3->SQL->Add( "select * from riwayat_transaksi   order by no desc");
ADOQuery3->ExecSQL();
ADOQuery3->Open();
ADOQuery3->Active=false;
ADOQuery3->Active=true;

Button2->Enabled=true;
Button9->Enabled=true;
Button10->Enabled=true;


//kodingan keuntungan

ADOQuery4->SQL->Clear();
//ADOQuery4->SQL->Add ("insert into pendapatan(tanggal, total_terjual, biaya_produksi, keuntungan) " + "SELECT CURRENT_DATE() AS tanggal, " + "(SUM(dada + paha_atas + paha_bawah + sayap + tempe + tahu)) AS total_terjual, " + "((SUM(dada + paha_atas + paha_bawah+ sayap) * 7500) + (SUM(tempe) * 2000) + (SUM(tahu) * 1000)) AS biaya_produksi, " + "((SUM(dada) * 6500) + (SUM(sayap) * 4500) + (SUM(paha_atas) * 5500) + (SUM(paha_bawah) * 3500) + (SUM(tempe) * 2000) + (SUM(tahu) * 1000)) AS keuntungan " + "from riwayat_transaksi");
AnsiString sqlQuery = "INSERT INTO pendapatan (tanggal, total_terjual, biaya_produksi, keuntungan) ""SELECT CURRENT_DATE() AS tanggal, ""(SUM(dada + paha_atas + paha_bawah + sayap + tempe + tahu)) AS total_terjual, ""((SUM(dada + paha_atas + paha_bawah + sayap) * 7500) + (SUM(tempe) * 2000) + (SUM(tahu) * 1000)) AS biaya_produksi, ""((SUM(dada) * 6500) + (SUM(sayap) * 4500) + (SUM(paha_atas) * 5500) + (SUM(paha_bawah) * 3500) + (SUM(tempe) * 2000) + (SUM(tahu) * 1000)) AS keuntungan ""FROM riwayat_transaksi";

ADOQuery4->SQL->Add(sqlQuery);


ADOQuery4->ExecSQL();

ADOQuery4->SQL->Clear();
ADOQuery4->SQL->Add( "select * from pendapatan order by total_terjual desc  ");
ADOQuery4->ExecSQL();
ADOQuery4->Open();
ADOQuery4->Active=false;
ADOQuery4->Active=true;




}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{

int jawab = Application->MessageBox("Cari nama di tabel SQL ?", "Konfirmasi", MB_YESNO | MB_ICONQUESTION);
String pilihan;

switch (jawab) {
    case IDYES:
    {
        pilihan = "SQL";
ShowMessage("Anda memilih: " + AnsiString(pilihan.c_str()));
AnsiString carinama = Edit10->Text;
ADOQuery3->SQL->Text = "SELECT * FROM riwayat_transaksi WHERE nama_pelanggan = '" + carinama + "'";
ADOQuery3->Open();

if (!ADOQuery1->Eof) {
    ShowMessage("Data ada");
}
else {
    //ShowMessage("Data tidak ditemukan");
}


        break;
    }
    case IDNO:
    {
        pilihan = "Riwayat";

ShowMessage("Anda memilih: " + AnsiString(pilihan.c_str()));
  bool cari = false;
  String cariNama = Edit10->Text;
  kasir* search = header;
  while(search != NULL){
        if(search->nama == cariNama){
           cari = true;
           ShowMessage("Data  Ditemukan");
           Edit10->Clear();
        }
     search = search->next;

  } if(cari == false){
        cari = false ;
        ShowMessage("Data Tidak Ditemukan");
        Edit10->Clear()  ;
  }
        break;
  }
}







}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button6Click(TObject *Sender)
{
Edit5->Clear();
Edit6->Text ="0";
Edit7->Text ="0";
Edit8->Text ="0";
ComboBox2->ClearSelection();
Button5->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
ListBox13->Clear();
ListBox14->Clear();
ListBox24->Clear();
Edit9->Clear();
Button7->Enabled=true;
        
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button9Click(TObject *Sender)
{

Button14->Enabled = true;
Button10->Enabled = true;
Form3->Show();
Form3->ListBox1->Clear();

    Form3->ListBox1->Items->Add("================================================================= ");
    Form3->ListBox1->Items->Add("                                      Ayam Kriuk             " );
    Form3->ListBox1->Items->Add("          Jl.Kampung Baru NO. 10, Pariaman-Sumatera Barat       ");
    Form3->ListBox1->Items->Add("================================================================= ");
    Form3->ListBox1->Items->Add("                          JAM BUKA : 10:00 - 22:00 WIB             ");
    Form3->ListBox1->Items->Add("");
    kasir*struk = footer;
    Form3->ListBox1->Items->Add("  Nama Pemesan   :  " + struk->nama);
    Form3->ListBox1->Items->Add("");

       if(cbb=="1. Dada")
       {
          if(Edit7 != "0" && Edit8 != "0"){
    Form3->ListBox1->Items->Add("  Dada Ayam  :""                               "+ IntToStr(pesan1) + " x   Rp.14000  =  "+ harga_dada);
    Form3->ListBox1->Items->Add("  Tahu            :""                               "+ IntToStr(pesan2) + " x   Rp.2000  =  "+ harga_tahu);
    Form3->ListBox1->Items->Add("  Tempe         :""                               "+ IntToStr(pesan3) + " x   Rp.3000  =  "+ harga_tempe);

          }else if( Edit7->Text != "0" && Edit8->Text == "0"){
    Form3->ListBox1->Items->Add("  Dada Ayam  :""                               "+ IntToStr(pesan1) + " x   Rp.14000  =  "+ harga_dada);
    Form3->ListBox1->Items->Add("  Tahu            :""                               "+ IntToStr(pesan2) + " x   Rp.2000  =  "+ harga_tahu);

          }else if( Edit7->Text == "0" && Edit8->Text != "0"){
    Form3->ListBox1->Items->Add("  Dada Ayam  :""                               "+ IntToStr(pesan1) + " x   Rp.14000  =  "+ harga_dada);
    Form3->ListBox1->Items->Add("  Tempe         :""                               "+ IntToStr(pesan3) + " x   Rp.3000  =  "+ harga_tempe);

          }else if( Edit7->Text == "0" && Edit8->Text == "0"){
    Form3->ListBox1->Items->Add("  Dada Ayam  :""                               "+ IntToStr(pesan1) + " x   Rp.14000  =  "+ harga_dada);
          }
       }

      else if(cbb== "2. Paha Atas")
      {
          if(Edit7 != "0" && Edit8 != "0"){
    Form3->ListBox1->Items->Add("  Paha Atas  :""                               "+ IntToStr(pesan1) + " x   Rp.13000  =  "+ harga_pahaA);
    Form3->ListBox1->Items->Add("  Tahu            :""                               "+ IntToStr(pesan2) + " x   Rp.2000  =  "+ harga_tahu);
    Form3->ListBox1->Items->Add("  Tempe         :""                               "+ IntToStr(pesan3) + " x   Rp.3000  =  "+ harga_tempe);

          }else if( Edit7->Text != "0" && Edit8->Text == "0"){
    Form3->ListBox1->Items->Add("  Paha Atas  :""                               "+ IntToStr(pesan1) + " x   Rp.13000  =  "+ harga_pahaA);
    Form3->ListBox1->Items->Add("  Tahu            :""                               "+ IntToStr(pesan2) + " x   Rp.2000  =  "+ harga_tahu);

          }else if( Edit7->Text == "0" && Edit8->Text != "0"){
    Form3->ListBox1->Items->Add("  Paha Atas  :""                               "+ IntToStr(pesan1) + " x   Rp.13000  =  "+ harga_pahaA);
    Form3->ListBox1->Items->Add("  Tempe         :""                               "+ IntToStr(pesan3) + " x   Rp.3000  =  "+ harga_tempe);

          }else if( Edit7->Text == "0" && Edit8->Text == "0"){
    Form3->ListBox1->Items->Add("  Paha Atas  :""                               "+ IntToStr(pesan1) + " x   Rp.13000  =  "+ harga_pahaA);
          }
      }

      else if(cbb== "2. Paha Bawah")
      {
          if(Edit7 != "0" && Edit8 != "0"){
    Form3->ListBox1->Items->Add("  Paha Bawah  :""                               "+ IntToStr(pesan1) + " x   Rp.11000  =  "+ harga_pahaB);
    Form3->ListBox1->Items->Add("  Tahu            :""                               "+ IntToStr(pesan2) + " x   Rp.2000  =  "+ harga_tahu);
    Form3->ListBox1->Items->Add("  Tempe         :""                               "+ IntToStr(pesan3) + " x   Rp.3000  =  "+ harga_tempe);

          }else if( Edit7->Text != "0" && Edit8->Text == "0"){
    Form3->ListBox1->Items->Add("  Paha Bawah  :""                               "+ IntToStr(pesan1) + " x   Rp.11000  =  "+ harga_pahaB);
    Form3->ListBox1->Items->Add("  Tahu            :""                               "+ IntToStr(pesan2) + " x   Rp.2000  =  "+ harga_tahu);

          }else if( Edit7->Text == "0" && Edit8->Text != "0"){
    Form3->ListBox1->Items->Add("  Paha Bawah  :""                               "+ IntToStr(pesan1) + " x   Rp.11000  =  "+ harga_pahaB);
    Form3->ListBox1->Items->Add("  Tempe         :""                               "+ IntToStr(pesan3) + " x   Rp.3000  =  "+ harga_tempe);

          }else if( Edit7->Text == "0" && Edit8->Text == "0"){
    Form3->ListBox1->Items->Add("  Paha Bawah  :""                               "+ IntToStr(pesan1) + " x   Rp.11000  =  "+ harga_pahaB);
          }
      }
      else if(cbb== "2. Sayap")
      {
          if(Edit7 != "0" && Edit8 != "0"){
    Form3->ListBox1->Items->Add("  Sayap ayam  :""                               "+ IntToStr(pesan1) + " x   Rp.12000  =  "+ harga_sayap);
    Form3->ListBox1->Items->Add("  Tahu            :""                               "+ IntToStr(pesan2) + " x   Rp.2000  =  "+ harga_tahu);
    Form3->ListBox1->Items->Add("  Tempe         :""                               "+ IntToStr(pesan3) + " x   Rp.3000  =  "+ harga_tempe);

          }else if( Edit7->Text != "0" && Edit8->Text == "0"){
    Form3->ListBox1->Items->Add("  Sayap ayam  :""                               "+ IntToStr(pesan1) + " x   Rp.12000  =  "+ harga_sayap);
    Form3->ListBox1->Items->Add("  Tahu            :""                               "+ IntToStr(pesan2) + " x   Rp.2000  =  "+ harga_tahu);

          }else if( Edit7->Text == "0" && Edit8->Text != "0"){
    Form3->ListBox1->Items->Add("  Sayap ayam  :""                               "+ IntToStr(pesan1) + " x   Rp.12000  =  "+ harga_sayap);
    Form3->ListBox1->Items->Add("  Tempe         :""                               "+ IntToStr(pesan3) + " x   Rp.3000  =  "+ harga_tempe);

          }else if( Edit7->Text == "0" && Edit8->Text == "0"){
    Form3->ListBox1->Items->Add("  Sayap ayam  :""                               "+ IntToStr(pesan1) + " x   Rp.12000  =  "+ harga_sayap);
          }
      }
    Form3->ListBox1->Items->Add("");
    Form3->ListBox1->Items->Add("");
    Form3->ListBox1->Items->Add("----------------------------------------------------------------------------------------------------------------");
    Form3->ListBox1->Items->Add("                                                            Total              : "+ IntToStr(struk->totalHarga) );
    Form3->ListBox1->Items->Add("                                                            Bayar             : "+ IntToStr(bayar) );
    Form3->ListBox1->Items->Add("                                                            Kembalian      : "+ IntToStr(kembalian));

    Form3->ListBox1->Items->Add("");
    Form3->ListBox1->Items->Add("");
    Form3->ListBox1->Items->Add("----------------------------------------------------------------------------------------------------------------");
    Form3->ListBox1->Items->Add("");
    Form3->ListBox1->Items->Add("");
    Form3->ListBox1->Items->Add("                                  SELAMAT MENIKMATI                       ");
    Form3->ListBox1->Items->Add("                  TERIMA KASIH ATAS KUNJUNGAN ANDA              ");

 Form3->ListBox1->Items->Add("======================================================================");

}
//---------------------------------------------------------------------------






void __fastcall TForm1::Button1Click(TObject *Sender)
{

bool found = false;
ADOQuery1->Open();

    while (!ADOQuery1->Eof)
    {
        AnsiString tanggalString = ADOQuery1->FieldByName("tanggal")->AsString;
        if (tanggalString == DateTimePicker1->Date)
        {
            found = true;
            // Periksa apakah data berubah
            int totalstok = ADOQuery1->FieldByName("total_stok_ayam")->AsInteger;
            int dadas = ADOQuery1->FieldByName("stok_dada")->AsInteger;
            int sayaps = ADOQuery1->FieldByName("stok_sayap")->AsInteger;
            int pahas = ADOQuery1->FieldByName("stok_paha_atas")->AsInteger;
            int pahbs = ADOQuery1->FieldByName("stok_paha_bawah")->AsInteger;
            int tempes = ADOQuery1->FieldByName("stok_tempe")->AsInteger;
            int tahus = ADOQuery1->FieldByName("stok_tahu")->AsInteger;

            if (totalstok != totStok || dadas != dds || sayaps != sys ||
                pahas != phas || pahbs != phbs || tempes != tempeS || tahus != tahuS)
            {
                // Perbarui data
                ADOQuery1->Edit();
                ADOQuery1->FieldByName("total_stok_ayma")->AsInteger = totStok;
                ADOQuery1->FieldByName("stok_dada")->AsInteger = dds;
                ADOQuery1->FieldByName("stok_sayap")->AsInteger = sys;
                ADOQuery1->FieldByName("stok_paha_bawah")->AsInteger = phbs;
                ADOQuery1->FieldByName("stok_paha_atas")->AsInteger = phas;
                ADOQuery1->FieldByName("stok_tempe")->AsInteger = tempeS;
                ADOQuery1->FieldByName("stok_tahu")->AsInteger = tahuS;
                ADOQuery1->Post(); // Simpan perubahan

            }

            break; // Keluar dari loop karena data telah ditemukan
        }

        ADOQuery1->Next();
    }

    // Jika tanggal tidak ditemukan, tambahkan baris baru ke ADOQuery1
    if (!found)
    {
        ADOQuery1->Append();
        ADOQuery1->FieldByName("tanggal")->AsString = DateTimePicker1->Date;
                ADOQuery1->FieldByName("total_stok_ayam")->AsInteger = totStok;
                ADOQuery1->FieldByName("stok_dada")->AsInteger = dds;
                ADOQuery1->FieldByName("stok_sayap")->AsInteger = sys;
                ADOQuery1->FieldByName("stok_paha_bawah")->AsInteger = phbs;
                ADOQuery1->FieldByName("stok_paha_atas")->AsInteger = phas;
                ADOQuery1->FieldByName("stok_tempe")->AsInteger = tempeS;
                ADOQuery1->FieldByName("stok_tahu")->AsInteger = tahuS;
        ADOQuery1->Post(); // Simpan baris baru
        ShowMessage("Data baru, tersimpan");
    }

ADOQuery1->SQL->Clear();
ADOQuery1->SQL->Add( "select * from stock   order by tanggal desc");
ADOQuery1->ExecSQL();
ADOQuery1->Open();
ADOQuery1->Active=false;
ADOQuery1->Active=true;

ADOQuery2->Open();

    kasir* tampil = head_stok;
    AnsiString mergedData; // Variabel untuk menyimpan data tergabung

    while (tampil != NULL)
    {
        mergedData += IntToStr(tampil->stok); // Menggabungkan nilai ke dalam string
        mergedData += " "; // Tambahkan spasi sebagai pemisah
        tampil = tampil->next;
    }

    // Cari tanggal yang sama di ADOQuery2

    ADOQuery2->First();
    while (!ADOQuery2->Eof)
    {
        AnsiString tanggalString = ADOQuery2->FieldByName("tanggal")->AsString;
        if (tanggalString == DateTimePicker1->Date)
        {
            found = true;
            // Perbarui data

            AnsiString existingData = ADOQuery2->FieldByName("link")->AsString;
            if (existingData != mergedData)
            {
                // Perbarui data
                ADOQuery2->Edit();
                ADOQuery2->FieldByName("link")->AsString = mergedData; // Set nilai kolom dengan data tergabung
                ADOQuery2->Post(); // Simpan perubahan

            }

            break; // Keluar dari loop karena data telah ditemukan
        }

        ADOQuery2->Next();
    }

    // Jika tanggal tidak ditemukan, tambahkan baris baru ke ADOQuery2
    if (!found)
    {
        ADOQuery2->Append();
        ADOQuery2->FieldByName("tanggal")->AsString = DateTimePicker1->Date;
        ADOQuery2->FieldByName("link")->AsString = mergedData; // Set nilai kolom dengan data tergabung
        ADOQuery2->Post(); // Simpan baris baru
    }
    ShowMessage("Data tersimpan");



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
Button18->Enabled=true;
Button12->Enabled=true;
Button10->Enabled=true;
Edit6->Text ="0";
Edit8->Text ="0";
Edit7->Text ="0";

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{

TDateTime tanggal = DateTimePicker1->Date; // Mengubah string menjadi objek TDateTime
TDateTime tanggalSebelumnya = tanggal - 1; // Mengurangi 1 hari dari tanggal
AnsiString tanggalSebelumnyaString = FormatDateTime("dd/mm/yyyy", tanggalSebelumnya); // Mengubah objek TDateTime menjadi string dengan format yang diinginkan


ADOQuery1->Open(); // Buka ADOTable
while (!ADOQuery1->Eof)
{
    AnsiString tanggalString = ADOQuery1->FieldByName("tanggal")->AsString; // Dapatkan nilai kolom tanggal sebagai string dari database

    if (tanggalString == tanggalSebelumnyaString)
{
    ListBox2->Items->Clear();
    ListBox3->Items->Clear();
    ListBox4->Items->Clear();
    ListBox5->Items->Clear();
    ListBox6->Items->Clear();
    ListBox7->Items->Clear();
    ListBox8->Items->Clear();


    ListBox2->Items->Add(IntToStr(ADOQuery1->FieldByName("total_stok_ayam")->AsInteger));
    totStok = ADOQuery1->FieldByName("total_stok_ayam")->AsInteger;
    ListBox3->Items->Add(IntToStr(ADOQuery1->FieldByName("stok_sayap")->AsInteger));
    sys = ADOQuery1->FieldByName("stok_sayap")->AsInteger;
    ListBox4->Items->Add(IntToStr(ADOQuery1->FieldByName("stok_dada")->AsInteger));
    dds = ADOQuery1->FieldByName("stok_dada")->AsInteger;
    ListBox5->Items->Add(IntToStr(ADOQuery1->FieldByName("stok_paha_bawah")->AsInteger));
    phbs = ADOQuery1->FieldByName("stok_paha_bawah")->AsInteger;
    ListBox6->Items->Add(IntToStr(ADOQuery1->FieldByName("stok_paha_atas")->AsInteger));
    phas = ADOQuery1->FieldByName("stok_paha_atas")->AsInteger;
    ListBox7->Items->Add(IntToStr(ADOQuery1->FieldByName("stok_tempe")->AsInteger));
    tempeS = ADOQuery1->FieldByName("stok_tempe")->AsInteger;
    ListBox8->Items->Add(IntToStr(ADOQuery1->FieldByName("stok_tahu")->AsInteger));
    tahuS = ADOQuery1->FieldByName("stok_tahu")->AsInteger;



    break; // Keluar dari loop karena data yang sesuai ditemukan
}

ADOQuery1->Next();

}


ADOQuery2->Open(); // Buka ADOTable

while (!ADOQuery2->Eof)
{
    AnsiString tanggalString = ADOQuery2->FieldByName("tanggal")->AsString; // Dapatkan nilai kolom tanggal sebagai string dari database

    if (tanggalString == tanggalSebelumnyaString)
{
    AnsiString dataString = ADOQuery2->FieldByName("link")->AsString;
    TStringList *dataList = new TStringList;
    dataList->Delimiter = ' ';
    dataList->DelimitedText = dataString;

    for (int i = 0; i < dataList->Count; i++)
    {
        int nilaiData = StrToInt(dataList->Strings[i]);

        kasir* baru = new kasir;
        baru->next = NULL;
        baru->stok = nilaiData;

        if (head_stok == NULL)
        {
            head_stok = baru;
            tail_stok = baru;
        }
        else
        {
            tail_stok->next = baru;
            tail_stok = baru;
        }
    }

    delete dataList;
}

ADOQuery2->Next();

}

ADOQuery2->Close(); // Tutup ADOTable

ListBox1->Items->Clear();
kasir *tampil = head_stok;
while (tampil != NULL) {
    if (tampil->stok > 0) {
        ListBox1->Items->Add(IntToStr(tampil->stok));
    }
    tampil = tampil->next;
}

Button2->Enabled=true;
Button3->Enabled=true;
Button1->Enabled=true;
Button5->Enabled=true;

}
//---------------------------------------------------------------------------






