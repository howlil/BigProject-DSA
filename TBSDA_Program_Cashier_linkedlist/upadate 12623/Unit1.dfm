object Form1: TForm1
  Left = 163
  Top = 176
  Width = 1277
  Height = 832
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 610
    Top = 10
    Width = 266
    Height = 27
    Caption = 'Program Kasir Kedai Ayam'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -25
    Font.Name = 'MS Serif'
    Font.Style = []
    ParentFont = False
  end
  object TGroupBox
    Left = 111
    Top = 46
    Width = 1357
    Height = 930
    Color = clScrollBar
    ParentColor = False
    TabOrder = 0
    object GroupBox3: TGroupBox
      Left = 10
      Top = 320
      Width = 356
      Height = 420
      Caption = 'Input Stok'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 0
      object Label2: TLabel
        Left = 148
        Top = 113
        Width = 52
        Height = 16
        Caption = 'Bungkus'
      end
      object Label3: TLabel
        Left = 148
        Top = 166
        Width = 43
        Height = 16
        Caption = 'Potong'
      end
      object Label4: TLabel
        Left = 148
        Top = 212
        Width = 43
        Height = 16
        Caption = 'Potong'
      end
      object Label6: TLabel
        Left = 20
        Top = 162
        Width = 31
        Height = 16
        Caption = 'Tahu'
      end
      object Label7: TLabel
        Left = 20
        Top = 202
        Width = 44
        Height = 16
        Caption = 'Tempe'
      end
      object Label8: TLabel
        Left = 66
        Top = 242
        Width = 121
        Height = 25
        Caption = 'Jumlah Stok'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label5: TLabel
        Left = 20
        Top = 113
        Width = 35
        Height = 16
        Caption = 'Ayam'
      end
      object Label9: TLabel
        Left = 30
        Top = 282
        Width = 34
        Height = 16
        Caption = 'Dada'
      end
      object Label10: TLabel
        Left = 177
        Top = 282
        Width = 40
        Height = 16
        Caption = 'Sayap'
      end
      object Label11: TLabel
        Left = 177
        Top = 331
        Width = 41
        Height = 16
        Caption = 'PahaB'
      end
      object Label13: TLabel
        Left = 20
        Top = 331
        Width = 41
        Height = 16
        Caption = 'PahaA'
      end
      object Label14: TLabel
        Left = 177
        Top = 378
        Width = 44
        Height = 16
        Caption = 'Tempe'
      end
      object Label15: TLabel
        Left = 20
        Top = 378
        Width = 31
        Height = 16
        Caption = 'Tahu'
      end
      object Button3: TButton
        Left = 217
        Top = 108
        Width = 92
        Height = 31
        Caption = 'Ambil'
        TabOrder = 0
        OnClick = Button3Click
      end
      object Edit2: TEdit
        Left = 69
        Top = 103
        Width = 70
        Height = 21
        TabOrder = 1
      end
      object ListBox4: TListBox
        Left = 69
        Top = 282
        Width = 60
        Height = 31
        ItemHeight = 16
        TabOrder = 2
      end
      object Edit3: TEdit
        Left = 69
        Top = 153
        Width = 70
        Height = 21
        TabOrder = 3
      end
      object Edit4: TEdit
        Left = 69
        Top = 202
        Width = 70
        Height = 21
        TabOrder = 4
      end
      object Button4: TButton
        Left = 217
        Top = 158
        Width = 92
        Height = 30
        Caption = 'restok'
        TabOrder = 5
        OnClick = Button4Click
      end
      object ListBox3: TListBox
        Left = 226
        Top = 282
        Width = 61
        Height = 31
        ItemHeight = 16
        TabOrder = 6
      end
      object ListBox5: TListBox
        Left = 226
        Top = 331
        Width = 61
        Height = 31
        ItemHeight = 16
        TabOrder = 7
      end
      object ListBox6: TListBox
        Left = 69
        Top = 331
        Width = 60
        Height = 31
        ItemHeight = 16
        TabOrder = 8
      end
      object ListBox7: TListBox
        Left = 226
        Top = 378
        Width = 61
        Height = 31
        ItemHeight = 16
        TabOrder = 9
      end
      object ListBox8: TListBox
        Left = 69
        Top = 378
        Width = 60
        Height = 31
        ItemHeight = 16
        TabOrder = 10
      end
      object ComboBox3: TComboBox
        Left = 65
        Top = 50
        Width = 149
        Height = 24
        BevelInner = bvLowered
        BevelKind = bkSoft
        ItemHeight = 16
        TabOrder = 11
        Text = 'Ambil bungkus Ayam'
        Items.Strings = (
          '1. Bungkus Kecil ( 4 )'
          '2. Bungkus Sedang ( 8 )'
          '3. Bungkus Besar ( 12 ) ')
      end
    end
    object GroupBox4: TGroupBox
      Left = 374
      Top = 10
      Width = 356
      Height = 273
      Caption = 'Penjualan'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 1
      object Label16: TLabel
        Left = 17
        Top = 28
        Width = 37
        Height = 16
        Caption = 'Nama'
      end
      object Label17: TLabel
        Left = 16
        Top = 73
        Width = 81
        Height = 16
        Caption = 'Bagian Ayam'
      end
      object Label18: TLabel
        Left = 14
        Top = 112
        Width = 89
        Height = 16
        Caption = 'Jumlah Potong'
      end
      object Label19: TLabel
        Left = 16
        Top = 153
        Width = 31
        Height = 16
        Caption = 'Tahu'
      end
      object Label20: TLabel
        Left = 15
        Top = 197
        Width = 44
        Height = 16
        Caption = 'Tempe'
      end
      object Button5: TButton
        Left = 148
        Top = 225
        Width = 80
        Height = 31
        Caption = 'Input'
        TabOrder = 0
        OnClick = Button5Click
      end
      object Edit5: TEdit
        Left = 150
        Top = 27
        Width = 163
        Height = 21
        TabOrder = 1
      end
      object Button6: TButton
        Left = 246
        Top = 225
        Width = 80
        Height = 31
        Caption = 'Next'
        TabOrder = 2
        OnClick = Button6Click
      end
      object ComboBox2: TComboBox
        Left = 150
        Top = 64
        Width = 165
        Height = 24
        ItemHeight = 16
        TabOrder = 3
        Items.Strings = (
          '1. Dada'
          '2. Paha Atas'
          '3. Paha Bawah'
          '4. Sayap')
      end
      object Edit6: TEdit
        Left = 150
        Top = 106
        Width = 78
        Height = 21
        TabOrder = 4
      end
      object Edit7: TEdit
        Left = 149
        Top = 146
        Width = 77
        Height = 21
        TabOrder = 5
      end
      object Edit8: TEdit
        Left = 149
        Top = 186
        Width = 75
        Height = 21
        TabOrder = 6
      end
    end
    object GroupBox2: TGroupBox
      Left = 10
      Top = 69
      Width = 356
      Height = 247
      Caption = 'Freezer'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 2
      object Label36: TLabel
        Left = 251
        Top = 118
        Width = 48
        Height = 16
        Caption = 'Sorting :'
      end
      object Button2: TButton
        Left = 246
        Top = 65
        Width = 92
        Height = 31
        Caption = 'Susun'
        TabOrder = 0
        OnClick = Button2Click
      end
      object Edit1: TEdit
        Left = 59
        Top = 65
        Width = 179
        Height = 21
        TabOrder = 1
      end
      object ListBox1: TListBox
        Left = 59
        Top = 100
        Width = 179
        Height = 91
        ItemHeight = 16
        TabOrder = 2
      end
      object ListBox2: TListBox
        Left = 59
        Top = 202
        Width = 179
        Height = 27
        ItemHeight = 16
        TabOrder = 3
      end
      object Button16: TButton
        Left = 246
        Top = 148
        Width = 92
        Height = 30
        Caption = 'descending'
        TabOrder = 4
        OnClick = Button16Click
      end
      object Button17: TButton
        Left = 246
        Top = 197
        Width = 92
        Height = 27
        Caption = 'ascending'
        TabOrder = 5
        OnClick = Button17Click
      end
    end
    object GroupBox5: TGroupBox
      Left = 374
      Top = 286
      Width = 356
      Height = 286
      Caption = 'Antri'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 3
      object Label21: TLabel
        Left = 34
        Top = 20
        Width = 18
        Height = 16
        Caption = 'No'
      end
      object Label22: TLabel
        Left = 70
        Top = 18
        Width = 37
        Height = 16
        Caption = 'Nama'
      end
      object Label23: TLabel
        Left = 192
        Top = 20
        Width = 17
        Height = 16
        Caption = 'Jlh'
      end
      object Label24: TLabel
        Left = 229
        Top = 20
        Width = 35
        Height = 16
        Caption = 'harga'
      end
      object Button7: TButton
        Left = 207
        Top = 238
        Width = 97
        Height = 29
        Caption = 'panggil'
        TabOrder = 0
        OnClick = Button7Click
      end
      object ListBox9: TListBox
        Left = 30
        Top = 43
        Width = 36
        Height = 176
        ItemHeight = 16
        TabOrder = 1
      end
      object ListBox10: TListBox
        Left = 69
        Top = 43
        Width = 122
        Height = 175
        ItemHeight = 16
        TabOrder = 2
      end
      object ListBox11: TListBox
        Left = 192
        Top = 42
        Width = 33
        Height = 176
        ItemHeight = 16
        TabOrder = 3
      end
      object ListBox12: TListBox
        Left = 224
        Top = 42
        Width = 85
        Height = 176
        ItemHeight = 16
        TabOrder = 4
      end
      object Edit11: TEdit
        Left = 30
        Top = 236
        Width = 158
        Height = 21
        TabOrder = 5
      end
    end
    object GroupBox6: TGroupBox
      Left = 738
      Top = 14
      Width = 356
      Height = 184
      Caption = 'Bayar'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 4
      object Label25: TLabel
        Left = 31
        Top = 33
        Width = 31
        Height = 16
        Caption = 'Total'
      end
      object Label12: TLabel
        Left = 34
        Top = 65
        Width = 36
        Height = 16
        Caption = 'Bayar'
      end
      object Label26: TLabel
        Left = 34
        Top = 97
        Width = 64
        Height = 16
        Caption = 'Kembalian'
      end
      object ListBox13: TListBox
        Left = 138
        Top = 25
        Width = 159
        Height = 27
        ItemHeight = 16
        TabOrder = 0
      end
      object Edit9: TEdit
        Left = 138
        Top = 59
        Width = 157
        Height = 21
        TabOrder = 1
      end
      object ListBox14: TListBox
        Left = 137
        Top = 92
        Width = 162
        Height = 27
        ItemHeight = 16
        TabOrder = 2
      end
      object Button8: TButton
        Left = 135
        Top = 133
        Width = 80
        Height = 31
        Caption = 'Bayar'
        TabOrder = 3
        OnClick = Button8Click
      end
      object Button9: TButton
        Left = 28
        Top = 137
        Width = 73
        Height = 32
        Caption = 'Struk'
        TabOrder = 4
        OnClick = Button9Click
      end
      object Button14: TButton
        Left = 224
        Top = 133
        Width = 73
        Height = 31
        Caption = 'Clear'
        TabOrder = 5
        OnClick = Button14Click
      end
    end
    object GroupBox7: TGroupBox
      Left = 738
      Top = 206
      Width = 592
      Height = 366
      Caption = 'Riwayat Transaksi'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 5
      object Label27: TLabel
        Left = 34
        Top = 20
        Width = 18
        Height = 16
        Caption = 'No'
      end
      object Label28: TLabel
        Left = 70
        Top = 18
        Width = 37
        Height = 16
        Caption = 'Nama'
      end
      object Label29: TLabel
        Left = 245
        Top = 20
        Width = 20
        Height = 16
        Caption = 'DD'
      end
      object Label30: TLabel
        Left = 443
        Top = 20
        Width = 72
        Height = 16
        Caption = 'Total Harga'
      end
      object Label31: TLabel
        Left = 281
        Top = 20
        Width = 18
        Height = 16
        Caption = 'PA'
      end
      object Label32: TLabel
        Left = 313
        Top = 20
        Width = 18
        Height = 16
        Caption = 'PB'
      end
      object Label33: TLabel
        Left = 345
        Top = 20
        Width = 9
        Height = 16
        Caption = 'S'
      end
      object Label34: TLabel
        Left = 378
        Top = 18
        Width = 19
        Height = 16
        Caption = 'TH'
      end
      object Label35: TLabel
        Left = 406
        Top = 18
        Width = 18
        Height = 16
        Caption = 'TP'
      end
      object ListBox15: TListBox
        Left = 30
        Top = 44
        Width = 36
        Height = 312
        ItemHeight = 16
        TabOrder = 0
      end
      object ListBox16: TListBox
        Left = 69
        Top = 44
        Width = 176
        Height = 312
        ItemHeight = 16
        TabOrder = 1
      end
      object ListBox17: TListBox
        Left = 244
        Top = 43
        Width = 37
        Height = 311
        ItemHeight = 16
        TabOrder = 2
      end
      object ListBox18: TListBox
        Left = 439
        Top = 44
        Width = 136
        Height = 312
        ItemHeight = 16
        TabOrder = 3
      end
      object ListBox19: TListBox
        Left = 274
        Top = 43
        Width = 37
        Height = 311
        ItemHeight = 16
        TabOrder = 4
      end
      object ListBox20: TListBox
        Left = 306
        Top = 44
        Width = 37
        Height = 312
        ItemHeight = 16
        TabOrder = 5
      end
      object ListBox21: TListBox
        Left = 340
        Top = 44
        Width = 37
        Height = 312
        ItemHeight = 16
        TabOrder = 6
      end
      object ListBox22: TListBox
        Left = 372
        Top = 44
        Width = 37
        Height = 312
        ItemHeight = 16
        TabOrder = 7
      end
      object ListBox23: TListBox
        Left = 404
        Top = 44
        Width = 37
        Height = 312
        ItemHeight = 16
        TabOrder = 8
      end
    end
    object GroupBox9: TGroupBox
      Left = 374
      Top = 578
      Width = 955
      Height = 160
      Caption = 'Rekap Hasil Penjualan'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 6
      object DBGrid1: TDBGrid
        Left = 16
        Top = 25
        Width = 911
        Height = 119
        DataSource = DataSource2
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -13
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
    end
    object GroupBox8: TGroupBox
      Left = 1103
      Top = 81
      Width = 229
      Height = 117
      Caption = 'cari pelanggan'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 7
      object Edit10: TEdit
        Left = 22
        Top = 28
        Width = 196
        Height = 21
        TabOrder = 0
      end
      object Button10: TButton
        Left = 23
        Top = 68
        Width = 195
        Height = 30
        Caption = 'cari'
        TabOrder = 1
        OnClick = Button10Click
      end
    end
    object GroupBox10: TGroupBox
      Left = 10
      Top = 745
      Width = 808
      Height = 152
      Caption = 'data base stok'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 8
      object DBGrid2: TDBGrid
        Left = 10
        Top = 27
        Width = 789
        Height = 122
        DataSource = DataSource1
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -13
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
    end
    object Button18: TButton
      Left = 256
      Top = 30
      Width = 92
      Height = 30
      Caption = 'Import stok'
      TabOrder = 9
      OnClick = Button18Click
    end
    object DateTimePicker1: TDateTimePicker
      Left = 59
      Top = 30
      Width = 169
      Height = 24
      CalAlignment = dtaLeft
      Date = 45088
      Time = 45088
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 10
    end
    object GroupBox1: TGroupBox
      Left = 827
      Top = 748
      Width = 502
      Height = 150
      Caption = 'Keuntungan'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 11
      object DBGrid3: TDBGrid
        Left = 10
        Top = 20
        Width = 464
        Height = 119
        DataSource = DataSource3
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -13
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
    end
    object Button1: TButton
      Left = 1122
      Top = 30
      Width = 93
      Height = 30
      Caption = 'Simpan Data'
      TabOrder = 12
      OnClick = Button1Click
    end
    object Button12: TButton
      Left = 1231
      Top = 30
      Width = 92
      Height = 30
      Caption = 'Tutup'
      TabOrder = 13
      OnClick = Button12Click
    end
  end
  object Button11: TButton
    Left = 20
    Top = 59
    Width = 80
    Height = 31
    Caption = 'buka'
    TabOrder = 1
    OnClick = Button11Click
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;User ID=root;Exte' +
      'nded Properties="DRIVER={MySQL ODBC 8.0 Unicode Driver};Server=l' +
      'ocalhost;Port=3306;Database=data_kasir"'
    LoginPrompt = False
    Left = 16
    Top = 104
  end
  object ADOQuery1: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from stock ')
    Left = 16
    Top = 136
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 16
    Top = 168
  end
  object ADOQuery2: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select* from stack'
      '')
    Left = 16
    Top = 272
  end
  object DataSource2: TDataSource
    DataSet = ADOQuery3
    Left = 16
    Top = 432
  end
  object ADOQuery3: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select*from riwayat_transaksi order by tanggal ')
    Left = 16
    Top = 400
  end
  object ADOQuery4: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select* from pendapatan')
    Left = 16
    Top = 512
  end
  object DataSource3: TDataSource
    DataSet = ADOQuery4
    Left = 16
    Top = 552
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'stack'
    Left = 16
    Top = 304
  end
end
