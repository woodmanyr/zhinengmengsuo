VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "MSCOMM32.OCX"
Object = "{CDE57A40-8B86-11D0-B3C6-00A0C90AEA82}#1.0#0"; "MSDATGRD.OCX"
Object = "{67397AA1-7FB1-11D0-B148-00A0C922E820}#6.0#0"; "MSADODC.OCX"
Begin VB.Form Form1 
   Caption         =   "RFIDѧ����Ԣ�Ž�ϵͳ"
   ClientHeight    =   7380
   ClientLeft      =   225
   ClientTop       =   870
   ClientWidth     =   10260
   LinkTopic       =   "Form1"
   ScaleHeight     =   7380
   ScaleWidth      =   10260
   StartUpPosition =   3  '����ȱʡ
   Begin VB.Frame Frame1 
      Caption         =   "����ˢ��"
      BeginProperty Font 
         Name            =   "����"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1695
      Left            =   480
      TabIndex        =   0
      Top             =   360
      Width           =   9255
      Begin VB.TextBox Text9 
         BeginProperty Font 
            Name            =   "����"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   7800
         TabIndex        =   20
         Top             =   1080
         Width           =   1095
      End
      Begin VB.TextBox Text6 
         BeginProperty Font 
            Name            =   "����"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   5160
         TabIndex        =   16
         Top             =   1080
         Width           =   1815
      End
      Begin VB.TextBox Text4 
         BeginProperty Font 
            Name            =   "����"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   390
         Left            =   1080
         TabIndex        =   8
         Top             =   1080
         Width           =   3015
      End
      Begin VB.TextBox Text3 
         BeginProperty Font 
            Name            =   "����"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   6480
         TabIndex        =   6
         Top             =   360
         Width           =   2535
      End
      Begin VB.TextBox Text2 
         BeginProperty Font 
            Name            =   "����"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   3960
         TabIndex        =   4
         Top             =   360
         Width           =   1575
      End
      Begin VB.TextBox Text1 
         BeginProperty Font 
            Name            =   "����"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   720
         TabIndex        =   2
         Top             =   360
         Width           =   2175
      End
      Begin VB.Label Label7 
         Caption         =   "���£�"
         BeginProperty Font 
            Name            =   "����"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   7200
         TabIndex        =   19
         Top             =   1080
         Width           =   855
      End
      Begin VB.Label Label6 
         Caption         =   "���ţ�"
         BeginProperty Font 
            Name            =   "����"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   4320
         TabIndex        =   15
         Top             =   1080
         Width           =   735
      End
      Begin VB.Label Label4 
         Caption         =   "ˢ��ʱ�䣺"
         BeginProperty Font 
            Name            =   "����"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   120
         TabIndex        =   7
         Top             =   1080
         Width           =   1215
      End
      Begin VB.Label Label3 
         Caption         =   "���룺"
         BeginProperty Font 
            Name            =   "����"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   5760
         TabIndex        =   5
         Top             =   360
         Width           =   735
      End
      Begin VB.Label Label2 
         Caption         =   "������"
         BeginProperty Font 
            Name            =   "����"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   3240
         TabIndex        =   3
         Top             =   360
         Width           =   735
      End
      Begin VB.Label Label1 
         Caption         =   "ѧ�ţ�"
         BeginProperty Font 
            Name            =   "����"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   615
         Left            =   120
         TabIndex        =   1
         Top             =   360
         Width           =   735
      End
   End
   Begin VB.TextBox Text8 
      Height          =   375
      Left            =   9240
      TabIndex        =   18
      Top             =   600
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.TextBox Text7 
      Height          =   270
      Left            =   9000
      TabIndex        =   17
      Top             =   720
      Visible         =   0   'False
      Width           =   255
   End
   Begin MSAdodcLib.Adodc Adodc2 
      Height          =   330
      Left            =   6360
      Top             =   2280
      Visible         =   0   'False
      Width           =   1200
      _ExtentX        =   2117
      _ExtentY        =   582
      ConnectMode     =   0
      CursorLocation  =   3
      IsolationLevel  =   -1
      ConnectionTimeout=   15
      CommandTimeout  =   30
      CursorType      =   3
      LockType        =   3
      CommandType     =   8
      CursorOptions   =   0
      CacheSize       =   50
      MaxRecords      =   0
      BOFAction       =   0
      EOFAction       =   0
      ConnectStringType=   1
      Appearance      =   1
      BackColor       =   -2147483643
      ForeColor       =   -2147483640
      Orientation     =   0
      Enabled         =   -1
      Connect         =   "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=�Ž���Ϣ.mdb;Persist Security Info=False"
      OLEDBString     =   "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=�Ž���Ϣ.mdb;Persist Security Info=False"
      OLEDBFile       =   ""
      DataSourceName  =   ""
      OtherAttributes =   ""
      UserName        =   ""
      Password        =   ""
      RecordSource    =   "select * from ˢ��ʱ�� order by ����;"
      Caption         =   "Adodc2"
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      _Version        =   393216
   End
   Begin MSAdodcLib.Adodc Adodc1 
      Height          =   375
      Left            =   8160
      Top             =   2160
      Visible         =   0   'False
      Width           =   1200
      _ExtentX        =   2117
      _ExtentY        =   661
      ConnectMode     =   0
      CursorLocation  =   3
      IsolationLevel  =   -1
      ConnectionTimeout=   15
      CommandTimeout  =   30
      CursorType      =   3
      LockType        =   3
      CommandType     =   8
      CursorOptions   =   0
      CacheSize       =   50
      MaxRecords      =   0
      BOFAction       =   0
      EOFAction       =   0
      ConnectStringType=   1
      Appearance      =   1
      BackColor       =   -2147483643
      ForeColor       =   -2147483640
      Orientation     =   0
      Enabled         =   -1
      Connect         =   ""
      OLEDBString     =   ""
      OLEDBFile       =   ""
      DataSourceName  =   ""
      OtherAttributes =   ""
      UserName        =   ""
      Password        =   ""
      RecordSource    =   ""
      Caption         =   "Adodc1"
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      _Version        =   393216
   End
   Begin VB.Timer Timer1 
      Left            =   4680
      Top             =   240
   End
   Begin VB.TextBox Text5 
      Height          =   270
      Left            =   2400
      TabIndex        =   13
      Text            =   "Text5"
      Top             =   120
      Visible         =   0   'False
      Width           =   1095
   End
   Begin MSCommLib.MSComm MSComm1 
      Left            =   480
      Top             =   6720
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      DTREnable       =   -1  'True
   End
   Begin VB.CommandButton Command1 
      Caption         =   "��ʷ��¼��ѯ"
      BeginProperty Font 
         Name            =   "����"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   480
      TabIndex        =   10
      Top             =   6840
      Visible         =   0   'False
      Width           =   9255
   End
   Begin VB.Frame Frame2 
      Caption         =   "��ʷ��¼"
      BeginProperty Font 
         Name            =   "����"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   4095
      Left            =   480
      TabIndex        =   9
      Top             =   2520
      Width           =   9255
      Begin MSDataGridLib.DataGrid DataGrid1 
         Height          =   3375
         Left            =   0
         TabIndex        =   11
         Top             =   480
         Visible         =   0   'False
         Width           =   9255
         _ExtentX        =   16325
         _ExtentY        =   5953
         _Version        =   393216
         HeadLines       =   1
         RowHeight       =   18
         FormatLocked    =   -1  'True
         BeginProperty HeadFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "����"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "����"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ColumnCount     =   6
         BeginProperty Column00 
            DataField       =   "ѧ��"
            Caption         =   "ѧ��"
            BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
               Type            =   0
               Format          =   ""
               HaveTrueFalseNull=   0
               FirstDayOfWeek  =   0
               FirstWeekOfYear =   0
               LCID            =   2052
               SubFormatType   =   0
            EndProperty
         EndProperty
         BeginProperty Column01 
            DataField       =   "����"
            Caption         =   "����"
            BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
               Type            =   0
               Format          =   ""
               HaveTrueFalseNull=   0
               FirstDayOfWeek  =   0
               FirstWeekOfYear =   0
               LCID            =   2052
               SubFormatType   =   0
            EndProperty
         EndProperty
         BeginProperty Column02 
            DataField       =   "����"
            Caption         =   "����"
            BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
               Type            =   0
               Format          =   ""
               HaveTrueFalseNull=   0
               FirstDayOfWeek  =   0
               FirstWeekOfYear =   0
               LCID            =   2052
               SubFormatType   =   0
            EndProperty
         EndProperty
         BeginProperty Column03 
            DataField       =   "����"
            Caption         =   "����"
            BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
               Type            =   0
               Format          =   ""
               HaveTrueFalseNull=   0
               FirstDayOfWeek  =   0
               FirstWeekOfYear =   0
               LCID            =   2052
               SubFormatType   =   0
            EndProperty
         EndProperty
         BeginProperty Column04 
            DataField       =   "����"
            Caption         =   "����"
            BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
               Type            =   0
               Format          =   ""
               HaveTrueFalseNull=   0
               FirstDayOfWeek  =   0
               FirstWeekOfYear =   0
               LCID            =   2052
               SubFormatType   =   0
            EndProperty
         EndProperty
         BeginProperty Column05 
            DataField       =   "ˢ��ʱ��"
            Caption         =   "ˢ��ʱ��"
            BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
               Type            =   0
               Format          =   ""
               HaveTrueFalseNull=   0
               FirstDayOfWeek  =   0
               FirstWeekOfYear =   0
               LCID            =   2052
               SubFormatType   =   0
            EndProperty
         EndProperty
         SplitCount      =   1
         BeginProperty Split0 
            BeginProperty Column00 
               ColumnWidth     =   1170.142
            EndProperty
            BeginProperty Column01 
               ColumnWidth     =   1349.858
            EndProperty
            BeginProperty Column02 
               ColumnWidth     =   1065.26
            EndProperty
            BeginProperty Column03 
               ColumnWidth     =   1035.213
            EndProperty
            BeginProperty Column04 
               ColumnWidth     =   1305.071
            EndProperty
            BeginProperty Column05 
               ColumnWidth     =   3435.024
            EndProperty
         EndProperty
      End
   End
   Begin VB.ComboBox Combo1 
      Height          =   300
      ItemData        =   "Form1.frx":0000
      Left            =   2280
      List            =   "Form1.frx":0013
      TabIndex        =   12
      Text            =   "Combo1"
      Top             =   5760
      Width           =   1335
   End
   Begin VB.Label Label5 
      Caption         =   "Label5"
      Height          =   495
      Left            =   4560
      TabIndex        =   14
      Top             =   3360
      Width           =   1215
   End
   Begin VB.Menu ���ڶ˺� 
      Caption         =   "������ѡ��"
      Begin VB.Menu ww 
         Caption         =   "1200"
      End
      Begin VB.Menu xx 
         Caption         =   "2400"
      End
      Begin VB.Menu yy 
         Caption         =   "4800"
      End
      Begin VB.Menu oo 
         Caption         =   "9600"
      End
      Begin VB.Menu qw 
         Caption         =   "56000"
      End
   End
   Begin VB.Menu aa 
      Caption         =   "���ں�ѡ��"
      Begin VB.Menu COM1 
         Caption         =   "COM1"
      End
      Begin VB.Menu COM2 
         Caption         =   "COM2"
      End
      Begin VB.Menu COM3 
         Caption         =   "COM3"
      End
      Begin VB.Menu COM4 
         Caption         =   "COM4"
      End
      Begin VB.Menu COM5 
         Caption         =   "COM5"
      End
   End
   Begin VB.Menu �˵� 
      Caption         =   "�˵�"
      Begin VB.Menu KSGZ 
         Caption         =   "��ʼ����"
      End
      Begin VB.Menu TZGZ 
         Caption         =   "ֹͣ����"
      End
      Begin VB.Menu uu 
         Caption         =   "��Ϣ����"
      End
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Dim vHour%, vState$
'Public qq  As Variant
 Dim Con As New ADODB.Connection
Dim rs As New ADODB.Recordset
Dim sq1 As String
Dim tt As Variant
  Dim gg As Variant
 'Dim g4 As Variant
Dim a As String
 Dim b As String
 Dim c As String
 'Dim MyInt As Variant

Private Sub COM1_Click() '���ں�ѡ��
 Combo1.ListIndex = 0
End Sub

Private Sub COM2_Click() '���ں�ѡ��
 Combo1.ListIndex = 1
   
End Sub

Private Sub COM3_Click() '���ں�ѡ��
 Combo1.ListIndex = 2
End Sub

Private Sub COM4_Click() '���ں�ѡ��
 Combo1.ListIndex = 3
End Sub

Private Sub COM5_Click() '���ں�ѡ��
 Combo1.ListIndex = 4
End Sub



Private Sub Command1_Click()
Set recRecordset1 = Adodc2.Recordset '���Ƽ�¼��

Dim sFilterStr As String
Dim xhtj As String 'ѧ������
Dim xmtj As String '��������
Dim bjtj As String '�༶����

'��ѯʱ�����ֶβ����Ĭ�ϲ�ѯȫ��
If Trim(Text6.Text) = "" Then
xhtj = ""
Else
xhtj = "���� like '*" & Trim(Text6.Text) & "*'"
End If


If Trim(Text7.Text) = "" Then
xmtj = ""
Else
xmtj = "���� like '*" & Trim(Text7.Text) & "*'"
End If


If Trim(Text8.Text) = "" Then
bjtj = ""
Else
xbtj = "�༶ like '*" & Trim(Text8.Text) & "*'"
End If

If Trim(Text6.Text) <> "" And Trim(Text7.Text) <> "" Then
xmtj = " and " & xmtj
End If

If (Trim(Text6.Text) <> "" Or Trim(Text7.Text) <> "") And Trim(Text8.Text) <> "" Then
xbtj = " and " & xbtj
End If

sFilterStr = Trim(sFilterStr & xhtj & xmtj & xbtj)


If sFilterStr = "" Then
Adodc2.RecordSource = "select * from  ˢ��ʱ�� order by ����"
Adodc2.Refresh
Else
recRecordset1.Filter = sFilterStr
End If
DataGrid1.Visible = True
Set DataGrid1.DataSource = Adodc2

End Sub



Private Sub MSComm1_OnComm()
Select Case MSComm1.CommEvent
  
      Case comEvReceive   ' �յ� RThreshold # of
     Dim hk As Variant
     hk = MSComm1.Input
     If hk = "A" Then
     tt = 2
       MSComm1.RThreshold = 8
    End If
    
      If hk = "B" Then
     tt = 3
       MSComm1.RThreshold = 8
    End If
     gg = hk
     
       If hk = "C" Then
     tt = 7
       MSComm1.RThreshold = 4
    End If
    If tt = 7 Then
       If gg <> "C" Then
       Text9.Text = hk & "��"
        MSComm1.RThreshold = 1
       End If
       End If
      If tt = 2 Then
     If gg <> "A" Then
       Text6.Text = gg
      Con.Open "provider=Microsoft.jet.OLEDB.4.0;data source=" & App.Path & "\�Ž���Ϣ.mdb"
    sq1 = "select * from �û���Ϣ where ����='" + gg + "'"
      rs.Open sq1, Con
     If rs.EOF Then
      Text3.Text = ""
        Text1.Text = ""
        Text2.Text = ""
        Text4.Text = ""
        Text9.Text = ""
      If MSComm1.PortOpen = True Then '��ֹ����û�д� �򿪷��ͳ���
     MSComm1.Output = "D"  '����Ƭ������E ����
      MSComm1.OutBufferCount = 0 '���ͻ��������
       End If
        MSComm1.RThreshold = 1
     MsgBox "�û�������,����...", vbExclamation, "��ѯ"
       Con.Close
            Set rs = Nothing
            Set Con = Nothing
     Exit Sub
      Else
      Text3.Text = ""
        Text1.Text = ""
        Text2.Text = ""
        Text4.Text = ""
        Text9.Text = ""
     If MSComm1.PortOpen = True Then '��ֹ����û�д� �򿪷��ͳ���
     MSComm1.Output = "E"  '����Ƭ������E ����
      MSComm1.OutBufferCount = 0 '���ͻ��������
       End If
     End If
        rs.Close
        Con.Close
        Set rs = Nothing
        Set Con = Nothing
     MSComm1.RThreshold = 1
     End If
      End If
      
      
      
     
      If tt = 3 Then
       If gg <> "B" And gg <> "C" Then
       
    Con.Open "provider=Microsoft.jet.OLEDB.4.0;data source=" & App.Path & "\�Ž���Ϣ.mdb"
    sq1 = "select * from �û���Ϣ where ����='" + Text6.Text + "' and ����='" + gg + "'"
      rs.Open sq1, Con
     
     If rs.EOF Then
     Text3.Text = ""
        Text1.Text = ""
        Text2.Text = ""
        Text4.Text = ""
        Text9.Text = ""
         If MSComm1.PortOpen = True Then '��ֹ����û�д� �򿪷��ͳ���
     MSComm1.Output = "F"  '����Ƭ������E ����
      MSComm1.OutBufferCount = 0 '���ͻ��������
       End If
         MSComm1.RThreshold = 1
    ' MsgBox "�������,����...", vbExclamation, "��ѯ"
       Con.Close
            Set rs = Nothing
            Set Con = Nothing
     Exit Sub
      Else
            Text2.Text = rs.Fields("����")
              Text3.Text = rs.Fields("����")
            Text1.Text = rs.Fields("ѧ��")
        Text4.Text = vState & a & "/" & b & "/" & c & "/" & Time
     
      If MSComm1.PortOpen = True Then '��ֹ����û�д� �򿪷��ͳ���
     MSComm1.Output = "G"  '����Ƭ������E ����
      MSComm1.OutBufferCount = 0 '���ͻ��������
       End If
     End If
        rs.Close
        Con.Close
        Set rs = Nothing
        Set Con = Nothing
     MSComm1.RThreshold = 1
     tt = 1
    
     Adodc1.connectionstring = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" & App.Path & "\�Ž���Ϣ.mdb;Persist Security Info=False"
   Adodc1.RecordSource = "select * from ˢ��ʱ��"
  Adodc1.Refresh
  
     Adodc1.Recordset.AddNew '����¼�¼
    Adodc1.Recordset("����").Value = Text3.Text
     Adodc1.Recordset("����").Value = Text2.Text
    Adodc1.Recordset("ѧ��").Value = Text1.Text
     Adodc1.Recordset("����").Value = Text6.Text
    Adodc1.Recordset("ˢ��ʱ��").Value = Text4.Text
     Adodc1.Recordset("����").Value = Text9.Text
    Adodc1.Recordset.Update   '����
    End If
    End If
        MSComm1.InBufferCount = 0
         Adodc2.Refresh
         DataGrid1.Visible = False
         Command1.Visible = True
         
        
         End Select
      
End Sub

Private Sub oo_Click() '���ò�����9600  2
MSComm1.Settings = "9600,n,8,1"
End Sub



Private Sub qw_Click() '���ò�����56000
MSComm1.Settings = "56000,n,8,1"
End Sub

Private Sub Timer1_Timer()
Text5.Text = vState & a & "/" & b & "/" & c & "/" & Time
End Sub

Private Sub Form_Load()
 Adodc1.connectionstring = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" & App.Path & "\�Ž���Ϣ.mdb;Persist Security Info=False"
 Adodc1.RecordSource = "select * from �û���Ϣ"
Timer1.Interval = 10
 Data = Now
 a = Format(Data, "yyyy")
 b = Format(Data, "mm")
 c = Format(Data, "dd")
End Sub

Private Sub KSGZ_Click()
 g4 = g4 + 1
If g4 = 1 Then
  'Call dd_Click
  
'Combo1.ListIndex = 0
'MSComm3.CommPort = 3
 MSComm1.InBufferSize = 8 '���÷��ؽ��ջ������Ĵ�С,���ַ�Ϊ��λ��
   MSComm1.OutBufferSize = 2
    If MSComm1.PortOpen = True Then '�ش���
     End If
    MSComm1.RThreshold = 1 '���ò����ز���oncomm�¼����ַ��������ַ�Ϊ��λ. Rthreshold Ϊ 1�����ջ������յ�ÿһ
    '���ַ�����ʹ MSComm �ؼ����� OnComm �¼���
     'MSComm1.SThreshold = 1 '
    MSComm1.InputLen = 0 '���ôӽ��ջ�������ȡ������,Ϊ0��ȡ����������
    MSComm1.InputMode = comInputModeText '���ı����Ƚ���
   
    MSComm1.InBufferCount = 0 '��ս��ջ�����
   '  MSComm1.PortOpen = True
    End If

On Error GoTo BLAK

If MSComm1.PortOpen = True Then
   MSComm1.PortOpen = False
   MSComm1.CommPort = Combo1.ListIndex + 1
   MSComm1.PortOpen = True
Else
  MSComm1.CommPort = Combo1.ListIndex + 1
  MSComm1.PortOpen = True
End If

Exit Sub
BLAK:
MsgBox "���ڲ����ڻ��߱�ռ��!", vbOKOnly, "��ʾ��Ϣ"
End Sub

Private Sub tt_Click() '���ò�����4800
MSComm1.Settings = "4800,n,8,1"
End Sub

Private Sub TZGZ_Click()
If MSComm1.PortOpen = True Then
MSComm1.PortOpen = False
End If
End Sub

Private Sub uu_Click()
Form2.Show
End Sub

Private Sub ww_Click() '���ò�����1200    2
MSComm1.Settings = "1200,n,8,1"
End Sub

Private Sub xx_Click() '���ò�����2400  2
MSComm1.Settings = "2400,n,8,1"
End Sub

Private Sub yy_Click() '���ò�����4800   2
MSComm1.Settings = "4800,n,8,1"
End Sub
