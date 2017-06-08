Module Serial_Read
    Function ReceiveSerialData(ByVal _SerialPort, ByVal _BaudRate, ByVal _DataBits) As String
        ' Receive strings from a serial port.
        Dim returnStr As String = ""

        Dim Serial_Object As IO.Ports.SerialPort = Nothing

        Try
            Serial_Object = My.Computer.Ports.OpenSerialPort(_SerialPort)
            Serial_Object.BaudRate = _BaudRate
            Serial_Object.DataBits = _DataBits
            Serial_Object.ReadTimeout = 10000
            Do
                Dim Incoming As String = Serial_Object.ReadLine()
                If Incoming Is Nothing Then
                    Exit Do
                Else
                    returnStr &= Incoming & vbCrLf
                End If
            Loop
        Catch ex_timeout As TimeoutException
            returnStr = "Error: Serial Port read timed out."
        Catch ex As Exception
            returnStr = "Error: Can't open Serial port or other error"
        Finally
            If Serial_Object IsNot Nothing Then Serial_Object.Close()
        End Try

        Return returnStr
    End Function
End Module
