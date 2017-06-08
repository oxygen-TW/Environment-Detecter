Public Class Form1
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        TextBox1.Text = ReceiveSerialData("COM4", 9600, 8)
    End Sub
End Class
