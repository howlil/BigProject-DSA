object Form1: TForm1
  Left = 237
  Top = 45
  Width = 1277
  Height = 833
  VertScrollBar.Position = 1
  Caption = 'o'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 560
    Top = 31
    Width = 225
    Height = 23
    Caption = 'Program Kasir Kedai Ayam'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Serif'
    Font.Style = []
    ParentFont = False
  end
  object TGroupBox
    Left = 154
    Top = 60
    Width = 1103
    Height = 756
    Color = clScrollBar
    ParentColor = False
    TabOrder = 0
    object GroupBox3: TGroupBox
      Left = 8
      Top = 260
      Width = 289
      Height = 341
      Caption = 'Input Stok'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 0
      object Label2: TLabel
        Left = 120
        Top = 92
        Width = 42
        Height = 13
        Caption = 'Bungkus'
      end
      object Label3: TLabel
        Left = 120
        Top = 135
        Width = 34
        Height = 13
        Caption = 'Potong'
      end
      object Label4: TLabel
        Left = 120
        Top = 172
        Width = 34
        Height = 13
        Caption = 'Potong'
      end
      object Label6: TLabel
        Left = 16
        Top = 132
        Width = 25
        Height = 13
        Caption = 'Tahu'
      end
      object Label7: TLabel
        Left = 16
        Top = 164
        Width = 33
        Height = 13
        Caption = 'Tempe'
      end
      object Label8: TLabel
        Left = 54
        Top = 197
        Width = 100
        Height = 20
        Caption = 'Jumlah Stok'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label5: TLabel
        Left = 16
        Top = 92
        Width = 26
        Height = 13
        Caption = 'Ayam'
      end
      object Label9: TLabel
        Left = 24
        Top = 229
        Width = 26
        Height = 13
        Caption = 'Dada'
      end
      object Label10: TLabel
        Left = 144
        Top = 229
        Width = 30
        Height = 13
        Caption = 'Sayap'
      end
      object Label11: TLabel
        Left = 144
        Top = 269
        Width = 32
        Height = 13
        Caption = 'PahaB'
      end
      object Label13: TLabel
        Left = 16
        Top = 269
        Width = 32
        Height = 13
        Caption = 'PahaA'
      end
      object Label14: TLabel
        Left = 144
        Top = 307
        Width = 33
        Height = 13
        Caption = 'Tempe'
      end
      object Label15: TLabel
        Left = 16
        Top = 307
        Width = 25
        Height = 13
        Caption = 'Tahu'
      end
      object Button3: TButton
        Left = 176
        Top = 88
        Width = 75
        Height = 25
        Caption = 'Ambil'
        TabOrder = 0
        OnClick = Button3Click
      end
      object Edit2: TEdit
        Left = 56
        Top = 84
        Width = 57
        Height = 21
        TabOrder = 1
      end
      object ListBox4: TListBox
        Left = 56
        Top = 229
        Width = 49
        Height = 25
        ItemHeight = 13
        TabOrder = 2
      end
      object Edit3: TEdit
        Left = 56
        Top = 124
        Width = 57
        Height = 21
        TabOrder = 3
      end
      object Edit4: TEdit
        Left = 56
        Top = 164
        Width = 57
        Height = 21
        TabOrder = 4
      end
      object Button4: TButton
        Left = 176
        Top = 128
        Width = 75
        Height = 25
        Caption = 'restok'
        TabOrder = 5
        OnClick = Button4Click
      end
      object ListBox3: TListBox
        Left = 184
        Top = 229
        Width = 49
        Height = 25
        ItemHeight = 13
        TabOrder = 6
      end
      object ListBox5: TListBox
        Left = 184
        Top = 269
        Width = 49
        Height = 25
        ItemHeight = 13
        TabOrder = 7
      end
      object ListBox6: TListBox
        Left = 56
        Top = 269
        Width = 49
        Height = 25
        ItemHeight = 13
        TabOrder = 8
      end
      object ListBox7: TListBox
        Left = 184
        Top = 307
        Width = 49
        Height = 25
        ItemHeight = 13
        TabOrder = 9
      end
      object ListBox8: TListBox
        Left = 56
        Top = 307
        Width = 49
        Height = 25
        ItemHeight = 13
        TabOrder = 10
      end
      object ComboBox3: TComboBox
        Left = 53
        Top = 41
        Width = 121
        Height = 21
        BevelInner = bvLowered
        BevelKind = bkSoft
        ItemHeight = 13
        TabOrder = 11
        Text = 'Ambil bungkus Ayam'
        Items.Strings = (
          '1. Bungkus Kecil ( 4 )'
          '2. Bungkus Sedang ( 8 )'
          '3. Bungkus Besar ( 12 ) ')
      end
    end
    object GroupBox4: TGroupBox
      Left = 304
      Top = 8
      Width = 289
      Height = 222
      Caption = 'Penjualan'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 1
      object Label16: TLabel
        Left = 14
        Top = 23
        Width = 28
        Height = 13
        Caption = 'Nama'
      end
      object Label17: TLabel
        Left = 13
        Top = 59
        Width = 62
        Height = 13
        Caption = 'Bagian Ayam'
      end
      object Label18: TLabel
        Left = 11
        Top = 91
        Width = 70
        Height = 13
        Caption = 'Jumlah Potong'
      end
      object Label19: TLabel
        Left = 13
        Top = 124
        Width = 25
        Height = 13
        Caption = 'Tahu'
      end
      object Label20: TLabel
        Left = 12
        Top = 160
        Width = 33
        Height = 13
        Caption = 'Tempe'
      end
      object Button5: TButton
        Left = 120
        Top = 183
        Width = 65
        Height = 25
        Caption = 'Input'
        TabOrder = 0
        OnClick = Button5Click
      end
      object Edit5: TEdit
        Left = 122
        Top = 22
        Width = 132
        Height = 21
        TabOrder = 1
      end
      object Button6: TButton
        Left = 200
        Top = 183
        Width = 65
        Height = 25
        Caption = 'Next'
        TabOrder = 2
        OnClick = Button6Click
      end
      object ComboBox2: TComboBox
        Left = 122
        Top = 52
        Width = 134
        Height = 21
        ItemHeight = 13
        TabOrder = 3
        Items.Strings = (
          '1. Dada'
          '2. Paha Atas'
          '3. Paha Bawah'
          '4. Sayap')
      end
      object Edit6: TEdit
        Left = 122
        Top = 86
        Width = 63
        Height = 21
        TabOrder = 4
      end
      object Edit7: TEdit
        Left = 121
        Top = 119
        Width = 63
        Height = 21
        TabOrder = 5
      end
      object Edit8: TEdit
        Left = 121
        Top = 151
        Width = 61
        Height = 21
        TabOrder = 6
      end
    end
    object GroupBox2: TGroupBox
      Left = 8
      Top = 56
      Width = 289
      Height = 201
      Caption = 'Freezer'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 2
      object Label36: TLabel
        Left = 204
        Top = 96
        Width = 39
        Height = 13
        Caption = 'Sorting :'
      end
      object Button2: TButton
        Left = 200
        Top = 53
        Width = 75
        Height = 25
        Caption = 'Susun'
        TabOrder = 0
        OnClick = Button2Click
      end
      object Edit1: TEdit
        Left = 48
        Top = 53
        Width = 145
        Height = 21
        TabOrder = 1
      end
      object ListBox1: TListBox
        Left = 48
        Top = 81
        Width = 145
        Height = 74
        ItemHeight = 13
        TabOrder = 2
      end
      object ListBox2: TListBox
        Left = 48
        Top = 164
        Width = 145
        Height = 22
        ItemHeight = 13
        TabOrder = 3
      end
      object Button16: TButton
        Left = 200
        Top = 120
        Width = 75
        Height = 25
        Caption = 'descending'
        TabOrder = 4
        OnClick = Button16Click
      end
      object Button17: TButton
        Left = 200
        Top = 160
        Width = 75
        Height = 22
        Caption = 'ascending'
        TabOrder = 5
        OnClick = Button17Click
      end
    end
    object GroupBox5: TGroupBox
      Left = 304
      Top = 232
      Width = 289
      Height = 233
      Caption = 'Antri'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 3
      object Label21: TLabel
        Left = 28
        Top = 16
        Width = 14
        Height = 13
        Caption = 'No'
      end
      object Label22: TLabel
        Left = 57
        Top = 15
        Width = 28
        Height = 13
        Caption = 'Nama'
      end
      object Label23: TLabel
        Left = 156
        Top = 16
        Width = 13
        Height = 13
        Caption = 'Jlh'
      end
      object Label24: TLabel
        Left = 186
        Top = 16
        Width = 27
        Height = 13
        Caption = 'harga'
      end
      object Button7: TButton
        Left = 176
        Top = 192
        Width = 71
        Height = 25
        Caption = 'panggil'
        TabOrder = 0
        OnClick = Button7Click
      end
      object ListBox9: TListBox
        Left = 24
        Top = 35
        Width = 30
        Height = 143
        ItemHeight = 13
        TabOrder = 1
      end
      object ListBox10: TListBox
        Left = 56
        Top = 35
        Width = 99
        Height = 142
        ItemHeight = 13
        TabOrder = 2
      end
      object ListBox11: TListBox
        Left = 156
        Top = 34
        Width = 27
        Height = 143
        ItemHeight = 13
        TabOrder = 3
      end
      object ListBox12: TListBox
        Left = 182
        Top = 34
        Width = 69
        Height = 143
        ItemHeight = 13
        TabOrder = 4
      end
      object ListBox24: TListBox
        Left = 24
        Top = 192
        Width = 129
        Height = 25
        ItemHeight = 13
        TabOrder = 5
      end
    end
    object GroupBox6: TGroupBox
      Left = 600
      Top = 11
      Width = 289
      Height = 150
      Caption = 'Bayar'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 4
      object Label25: TLabel
        Left = 25
        Top = 27
        Width = 24
        Height = 13
        Caption = 'Total'
      end
      object Label12: TLabel
        Left = 28
        Top = 53
        Width = 27
        Height = 13
        Caption = 'Bayar'
      end
      object Label26: TLabel
        Left = 28
        Top = 79
        Width = 49
        Height = 13
        Caption = 'Kembalian'
      end
      object ListBox13: TListBox
        Left = 112
        Top = 20
        Width = 129
        Height = 22
        ItemHeight = 13
        TabOrder = 0
      end
      object Edit9: TEdit
        Left = 112
        Top = 48
        Width = 128
        Height = 21
        TabOrder = 1
      end
      object ListBox14: TListBox
        Left = 111
        Top = 75
        Width = 132
        Height = 22
        ItemHeight = 13
        TabOrder = 2
      end
      object Button8: TButton
        Left = 110
        Top = 108
        Width = 65
        Height = 25
        Caption = 'Bayar'
        TabOrder = 3
        OnClick = Button8Click
      end
      object Button9: TButton
        Left = 23
        Top = 103
        Width = 59
        Height = 26
        Caption = 'Struk'
        TabOrder = 4
        OnClick = Button9Click
      end
      object Button14: TButton
        Left = 182
        Top = 108
        Width = 59
        Height = 25
        Caption = 'Clear'
        TabOrder = 5
        OnClick = Button14Click
      end
    end
    object GroupBox7: TGroupBox
      Left = 600
      Top = 167
      Width = 481
      Height = 298
      Caption = 'Riwayat Transaksi'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 5
      object Label27: TLabel
        Left = 28
        Top = 16
        Width = 14
        Height = 13
        Caption = 'No'
      end
      object Label28: TLabel
        Left = 57
        Top = 15
        Width = 28
        Height = 13
        Caption = 'Nama'
      end
      object Label29: TLabel
        Left = 199
        Top = 16
        Width = 16
        Height = 13
        Caption = 'DD'
      end
      object Label30: TLabel
        Left = 360
        Top = 16
        Width = 56
        Height = 13
        Caption = 'Total Harga'
      end
      object Label31: TLabel
        Left = 228
        Top = 16
        Width = 14
        Height = 13
        Caption = 'PA'
      end
      object Label32: TLabel
        Left = 254
        Top = 16
        Width = 14
        Height = 13
        Caption = 'PB'
      end
      object Label33: TLabel
        Left = 280
        Top = 16
        Width = 7
        Height = 13
        Caption = 'S'
      end
      object Label34: TLabel
        Left = 307
        Top = 15
        Width = 15
        Height = 13
        Caption = 'TH'
      end
      object Label35: TLabel
        Left = 330
        Top = 15
        Width = 14
        Height = 13
        Caption = 'TP'
      end
      object ListBox15: TListBox
        Left = 24
        Top = 36
        Width = 30
        Height = 253
        ItemHeight = 13
        TabOrder = 0
      end
      object ListBox16: TListBox
        Left = 56
        Top = 36
        Width = 143
        Height = 253
        ItemHeight = 13
        TabOrder = 1
      end
      object ListBox17: TListBox
        Left = 198
        Top = 35
        Width = 30
        Height = 253
        ItemHeight = 13
        TabOrder = 2
      end
      object ListBox18: TListBox
        Left = 357
        Top = 36
        Width = 110
        Height = 253
        ItemHeight = 13
        TabOrder = 3
      end
      object ListBox19: TListBox
        Left = 223
        Top = 35
        Width = 30
        Height = 253
        ItemHeight = 13
        TabOrder = 4
      end
      object ListBox20: TListBox
        Left = 249
        Top = 36
        Width = 30
        Height = 253
        ItemHeight = 13
        TabOrder = 5
      end
      object ListBox21: TListBox
        Left = 276
        Top = 36
        Width = 30
        Height = 253
        ItemHeight = 13
        TabOrder = 6
      end
      object ListBox22: TListBox
        Left = 302
        Top = 36
        Width = 30
        Height = 253
        ItemHeight = 13
        TabOrder = 7
      end
      object ListBox23: TListBox
        Left = 328
        Top = 36
        Width = 30
        Height = 253
        ItemHeight = 13
        TabOrder = 8
      end
    end
    object GroupBox9: TGroupBox
      Left = 304
      Top = 470
      Width = 776
      Height = 130
      Caption = 'Rekap Hasil Penjualan'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 6
      object DBGrid1: TDBGrid
        Left = 13
        Top = 20
        Width = 740
        Height = 97
        DataSource = DataSource2
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -10
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
    end
    object GroupBox8: TGroupBox
      Left = 896
      Top = 66
      Width = 186
      Height = 95
      Caption = 'cari pelanggan'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 7
      object Edit10: TEdit
        Left = 18
        Top = 23
        Width = 159
        Height = 21
        TabOrder = 0
      end
      object Button10: TButton
        Left = 27
        Top = 55
        Width = 158
        Height = 25
        Caption = 'cari'
        TabOrder = 1
        OnClick = Button10Click
      end
    end
    object GroupBox10: TGroupBox
      Left = 8
      Top = 605
      Width = 657
      Height = 124
      Caption = 'data base stok'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 8
      object DBGrid2: TDBGrid
        Left = 8
        Top = 22
        Width = 641
        Height = 99
        DataSource = DataSource1
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -10
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
    end
    object Button18: TButton
      Left = 208
      Top = 24
      Width = 75
      Height = 25
      Caption = 'Import stok'
      TabOrder = 9
      OnClick = Button18Click
    end
    object DateTimePicker1: TDateTimePicker
      Left = 48
      Top = 24
      Width = 137
      Height = 21
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
      Left = 672
      Top = 608
      Width = 408
      Height = 122
      Caption = 'Keuntungan'
      Color = cl3DLight
      ParentColor = False
      TabOrder = 11
      object DBGrid3: TDBGrid
        Left = 8
        Top = 16
        Width = 377
        Height = 97
        DataSource = DataSource3
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -10
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
    end
    object Button1: TButton
      Left = 904
      Top = 24
      Width = 75
      Height = 25
      Caption = 'Simpan Data'
      TabOrder = 12
      OnClick = Button1Click
    end
    object Button12: TButton
      Left = 1000
      Top = 24
      Width = 75
      Height = 25
      Caption = 'Tutup'
      TabOrder = 13
      OnClick = Button12Click
    end
  end
  object Button11: TButton
    Left = 80
    Top = 71
    Width = 65
    Height = 25
    Caption = 'buka'
    TabOrder = 1
    OnClick = Button11Click
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'DRIVER={MySQL ODBC 8.0 Unicode Driver};User ID=root;Password=;Se' +
      'rver=localhost;Port=3306;Database=data_kasir;'
    LoginPrompt = False
    Left = 80
    Top = 128
  end
  object ADOQuery1: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from stock order by tanggal desc')
    Left = 80
    Top = 160
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 80
    Top = 192
  end
  object ADOQuery2: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select* from stack'
      '')
    Left = 80
    Top = 296
  end
  object DataSource2: TDataSource
    DataSet = ADOQuery3
    Left = 80
    Top = 456
  end
  object ADOQuery3: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select*from riwayat_transaksi  order by no desc')
    Left = 80
    Top = 424
  end
  object ADOQuery4: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select* from pendapatan order by total_terjual desc')
    Left = 80
    Top = 536
  end
  object DataSource3: TDataSource
    DataSet = ADOQuery4
    Left = 80
    Top = 576
  end
  object ADOTable1: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'stack'
    Left = 80
    Top = 328
  end
end
