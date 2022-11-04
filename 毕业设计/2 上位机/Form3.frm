VERSION 5.00
Begin VB.Form Form3 
   Caption         =   "登入界面"
   ClientHeight    =   3210
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   4650
   LinkTopic       =   "Form3"
   ScaleHeight     =   3210
   ScaleWidth      =   4650
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox Text1 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   1740
      TabIndex        =   3
      Top             =   600
      Width           =   1875
   End
   Begin VB.CommandButton Command1 
      Caption         =   "确定"
      Height          =   495
      Left            =   1020
      TabIndex        =   2
      Top             =   2220
      Width           =   975
   End
   Begin VB.CommandButton Command2 
      Caption         =   "取消"
      Height          =   495
      Left            =   2580
      TabIndex        =   1
      Top             =   2220
      Width           =   1095
   End
   Begin VB.TextBox Text2 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   435
      IMEMode         =   3  'DISABLE
      Left            =   1740
      PasswordChar    =   "*"
      TabIndex        =   0
      Top             =   1260
      Width           =   1875
   End
   Begin VB.Label Label1 
      BackStyle       =   0  'Transparent
      Caption         =   "用户"
      Height          =   435
      Left            =   1020
      TabIndex        =   5
      Top             =   600
      Width           =   615
   End
   Begin VB.Label Label2 
      BackStyle       =   0  'Transparent
      Caption         =   "密码"
      Height          =   375
      Left            =   960
      TabIndex        =   4
      Top             =   1260
      Width           =   615
   End
End
Attribute VB_Name = "Form3"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Command1_Click()
Dim sql As String
Dim rs_login As New ADODB.Recordset
If Trim(Text1.Text) = "" Then            '判断输入的用户名是否为空
   MsgBox "没有这个用户", vbOKOnly + vbExclamation, ""
   Text1.SetFocus
Else
   sql = "select * from 用户信息表 where 用户名='" & Text1.Text & "'"
   rs_login.Open sql, conn, adOpenKeyset, adLockPessimistic
   If rs_login.EOF = True Then
      MsgBox "没有这个用户", vbOKOnly + vbExclamation, ""
      Text1.SetFocus
   Else                                  '检验密码是否正确
      If Trim(rs_login.Fields(2)) = Trim(Text2.Text) Then
          userID = Text1.Text
         ' userpow = rs_login.Fields(2)
          rs_login.Close
          Unload Me
          Form1.Show
      Else
         MsgBox "密码不正确", vbOKOnly + vbExclamation, ""
         Text2.SetFocus
      End If
   End If
End If
cnt = cnt + 1
If cnt = 3 Then
   Unload Me
End If
Exit Sub
End Sub

Private Sub Command2_Click()
Unload Me
End Sub

Private Sub Form_Load()
Dim connectionstring As String
connectionstring = "provider=Microsoft.Jet.oledb.4.0;" & _
                   "data source=门禁信息.mdb"
conn.Open connectionstring
cnt = 0
End Sub








