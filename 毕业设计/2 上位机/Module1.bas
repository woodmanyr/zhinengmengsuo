Attribute VB_Name = "Module1"
Option Explicit
Public conn As New ADODB.Connection     '标记连接对象
Public select_menu As String            '标记所选择的菜单
Public userID As String                 '标记当前用户ID
Public userpow As String                '标记用户权限
Public book_num As String              '要借的书的编号



