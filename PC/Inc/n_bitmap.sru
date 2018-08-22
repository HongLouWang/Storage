$PBExportHeader$n_bitmap.sru
forward
global type n_bitmap from nonvisualobject
end type
type bitmapfileheader from structure within n_bitmap
end type
type bitmapinfoheader from structure within n_bitmap
end type
type bitmapinfo from structure within n_bitmap
end type
end forward

type bitmapfileheader from structure
	integer		bftype
	long		bfsize
	integer		bfreserved1
	integer		bfreserved2
	long		bfoffbits
end type

type bitmapinfoheader from structure
	long		bisize
	long		biwidth
	long		biheight
	integer		biplanes
	integer		bibitcount
	long		bicompression
	long		bisizeimage
	long		bixpelspermeter
	long		biypelspermeter
	long		biclrused
	long		biclrimportant
end type

type bitmapinfo from structure
	bitmapinfoheader		bmiheader
	unsignedlong		bmicolors[]
end type

global type n_bitmap from nonvisualobject autoinstantiate
end type

type prototypes
Function ulong GetLastError( ) Library "kernel32.dll"

Function ulong FormatMessage( &
	ulong dwFlags, &
	ulong lpSource, &
	ulong dwMessageId, &
	ulong dwLanguageId, &
	Ref string lpBuffer, &
	ulong nSize, &
	ulong Arguments &
	) Library "kernel32.dll" Alias For "FormatMessageA;Ansi"

Function int GetTempPath ( &
	int nBufferLength, &
	Ref string lpBuffer &
	) Library "kernel32.dll" Alias For "GetTempPathA;Ansi"

Function ulong GetDesktopWindow ( &
	) Library "user32.dll"

Function ulong GetDC ( &
	ulong hWnd &
	) Library "user32.dll"

Function ulong CreateCompatibleDC ( &
	ulong hdc &
	) Library "gdi32.dll"

Function ulong CreateCompatibleBitmap ( &
	ulong hdc, &
	int nWidth, &
	int nHeight &
	) Library "gdi32.dll"

Function ulong SelectObject ( &
	ulong hdc, &
	ulong hgdiobj &
	) Library "gdi32.dll"

Function boolean BitBlt ( &
	ulong hdcDest, &
	int nXDest, &
	int nYDest, &
	int nWidth, &
	int nHeight, &
	ulong hdcSrc, &
	int nXSrc, &
	int nYSrc, &
	long dwRop &
	) Library "gdi32.dll"

Function int GetDIBits ( &
	ulong hdc, &
	ulong hbmp, &
	uint uStartScan, &
	uint cScanLines, &
	Ref blob lpvBits, &
	Ref bitmapinfo lpbi, &
	uint uUsage &
	) Library "gdi32.dll" alias for "GetDIBits;Ansi"

Function int GetDIBits ( &
	ulong hdc, &
	ulong hbmp, &
	uint uStartScan, &
	uint cScanLines, &
	ulong lpvBits, &
	ref bitmapinfo lpbi, &
	uint uUsage &
	) Library "gdi32.dll" alias for "GetDIBits;Ansi"

Subroutine CopyBitmapFileHeader ( &
	Ref blob Destination, &
	bitmapfileheader Source, &
	long Length &
	) Library "kernel32.dll" Alias For "RtlMoveMemory;Ansi"

Subroutine CopyBitmapInfo ( &
	Ref blob Destination, &
	bitmapinfo Source, &
	long Length &
	) Library "kernel32.dll" Alias For "RtlMoveMemory;Ansi"

Function boolean DeleteDC ( &
	ulong hdc &
	) Library "gdi32.dll"

Function int ReleaseDC ( &
	ulong hWnd, &
	ulong hDC &
	) Library "user32.dll"

Function boolean OpenClipboard ( &
	ulong hWndNewOwner &
	) Library "user32.dll"

Function boolean EmptyClipboard ( &
	) Library "user32.dll"

Function boolean CloseClipboard ( &
	) Library "user32.dll"

Function ulong SetClipboardData ( &
	uint uFormat, &
	ulong hMem &
	) Library "user32.dll"

Function ulong CreateFile ( &
	string lpFileName, &
	ulong dwDesiredAccess, &
	ulong dwShareMode, &
	ulong lpSecurityAttributes, &
	ulong dwCreationDisposition, &
	ulong dwFlagsAndAttributes, &
	ulong hTemplateFile &
	) Library "kernel32.dll" Alias For "CreateFileA;Ansi"

Function boolean WriteFile ( &
	ulong hFile, &
	blob lpBuffer, &
	ulong nNumberOfBytesToWrite, &
	Ref ulong lpNumberOfBytesWritten, &
	ulong lpOverlapped &
	) Library "kernel32.dll"

Function boolean CloseHandle ( &
	ulong hObject &
	) Library "kernel32.dll"

end prototypes

type variables
Constant uint CF_BITMAP = 2
Constant long SRCCOPY = 13369376
Constant uint DIB_PAL_COLORS = 1
Constant uint DIB_RGB_COLORS = 0
Constant integer BITMAPTYPE = 19778
end variables

forward prototypes
public function string of_gettemppath ()
public function unsignedlong of_writeblob (string as_filename, blob ablb_bitmap)
public function blob of_capture (unsignedlong aul_hwnd, unsignedlong aul_xpos, unsignedlong aul_ypos, unsignedlong aul_width, unsignedlong aul_height, boolean ab_clipboard)
public function blob of_controlcapture (dragobject a_object, boolean ab_clipboard)
public function blob of_screencapture (boolean ab_clipboard)
public function blob of_windowcapture (window a_window, boolean ab_clipboard)
public function string of_getlasterror ()
end prototypes

public function string of_gettemppath ();// returns temp directory name

String ls_path
Integer li_buflen

li_buflen = 250
ls_path = Space(li_buflen)

GetTempPath(li_buflen, ls_path)

Return ls_path

end function

public function unsignedlong of_writeblob (string as_filename, blob ablb_bitmap);Constant ULong INVALID_HANDLE_VALUE = -1
Constant ULong GENERIC_WRITE    = 1073741824
Constant ULong FILE_SHARE_WRITE = 2
Constant ULong CREATE_ALWAYS		= 2

ULong lul_file, lul_length, lul_written
Boolean lb_rtn

// open file for write
lul_file = CreateFile(as_filename, GENERIC_WRITE, &
					FILE_SHARE_WRITE, 0, CREATE_ALWAYS, 0, 0)
If lul_file = INVALID_HANDLE_VALUE Then
	Return -999
End If

// write file to disk
lul_length = Len(ablb_bitmap)
lb_rtn = WriteFile(lul_file, ablb_bitmap, &
					lul_length, lul_written, 0)

// close the file
CloseHandle(lul_file)

Return 0

end function

public function blob of_capture (unsignedlong aul_hwnd, unsignedlong aul_xpos, unsignedlong aul_ypos, unsignedlong aul_width, unsignedlong aul_height, boolean ab_clipboard);// capture bitmap and return as blob

ULong lul_hdc, lul_hdcMem, lul_hBitmap, lul_pixels
Blob lblb_header, lblb_info, lblb_bitmap
BitmapInfo lstr_Info
BitmapFileHeader lstr_Header

// Get the device context of window and allocate memory
lul_hdc = GetDC(aul_hWnd)
lul_hdcMem = CreateCompatibleDC(lul_hdc)
lul_hBitmap = CreateCompatibleBitmap(lul_hdc, aul_width, aul_height)

If lul_hBitmap <> 0 Then
	// Copy the bitmap to memory location
	SelectObject(lul_hdcMem, lul_hBitmap)
   BitBlt(lul_hdcMem, 0, 0, aul_width, aul_height, &
						lul_hdc, aul_xpos, aul_ypos, SRCCOPY)
	// try to store the bitmap into a blob so we can save it
	lstr_Info.bmiHeader.biSize = 40
	// Get the bitmapinfo
	If GetDIBits(lul_hdcMem, lul_hBitmap, 0, aul_height, &
							0, lstr_Info, DIB_RGB_COLORS) > 0 Then
		lul_pixels = lstr_Info.bmiHeader.biBitCount
		lstr_Info.bmiColors[lul_pixels] = 0
		lblb_bitmap = Blob(Space(lstr_Info.bmiHeader.biSizeImage))
		// get the actual bits
		GetDIBits(lul_hdcMem, lul_hBitmap, 0, aul_height, &
							lblb_bitmap, lstr_Info, DIB_RGB_COLORS) 
		// create a bitmap header
		lstr_Header.bfType = BITMAPTYPE
		lstr_Header.bfSize = lstr_Info.bmiHeader.biSizeImage
		lstr_Header.bfOffBits = 54 + (lul_pixels * 4)
		// copy the header structure to a blob
		lblb_header = Blob(Space(14))
		CopyBitmapFileHeader(lblb_header, lstr_Header, 14)
		// copy the info structure to a blob
		lblb_Info = Blob(Space(40  + lul_pixels * 4))
		CopyBitmapInfo(lblb_Info, lstr_Info, 40 + lul_pixels * 4)
		// add all together and we have a window bitmap in a blob
		lblb_bitmap = lblb_header + lblb_info + lblb_bitmap
	End If
End If

// paste bitmap to clipboard
If ab_clipboard Then
	If OpenClipboard(aul_hWnd) Then
		EmptyClipboard()
		SetClipboardData(CF_BITMAP, lul_hBitmap)
		CloseClipboard()
	Else
		MessageBox("OpenClipboard Failed", of_GetLastError())
	End If
End If

// Clean up handles
DeleteDC(lul_hdcMem)
ReleaseDC(aul_hWnd, lul_hdc)

Return lblb_bitmap

end function

public function blob of_controlcapture (dragobject a_object, boolean ab_clipboard);// capture bitmap of a control

PowerObject lpo_parent
ULong lul_xpos, lul_ypos, lul_width, lul_height, lul_hWnd

// loop thru parents until a window is found
lpo_parent = a_object.GetParent()
Do While lpo_parent.TypeOf() <> Window! and IsValid (lpo_parent)
	lpo_parent = lpo_parent.GetParent()
Loop

// get handle to window
lul_hWnd = Handle(lpo_parent)

// convert x, y, width and height from PBU to Pixels
lul_xpos   = UnitsToPixels(LN_OKX, XUnitsToPixels!)
lul_ypos   = UnitsToPixels(LN_OKY, YUnitsToPixels!)
//lul_width  = UnitsToPixels(a_object.width - 40, XUnitsToPixels!)
//lul_height = UnitsToPixels(a_object.height - 80, YUnitsToPixels!)


lul_width  = UnitsToPixels(LN_OKWIDTH, XUnitsToPixels!)
lul_height = UnitsToPixels(LN_OKHEIGHT, YUnitsToPixels!)

Return this.of_Capture(lul_hWnd, &
					lul_xpos, lul_ypos, lul_width, &
					lul_height, ab_clipboard)

end function

public function blob of_screencapture (boolean ab_clipboard);// capture bitmap of entire screen

ULong lul_hWnd, lul_width, lul_height
Environment le_env

// get screen size
GetEnvironment(le_env)
lul_width  = le_env.ScreenWidth
lul_height = le_env.ScreenHeight

// get handle to windows background
lul_hWnd = GetDesktopWindow()

Return this.of_Capture(lul_hWnd, &
					0, 0, lul_width, &
					lul_height, ab_clipboard)

end function

public function blob of_windowcapture (window a_window, boolean ab_clipboard);// capture bitmap of a window

ULong lul_xpos, lul_ypos, lul_width, lul_height, lul_hWnd

// get handle to windows background
lul_hWnd = GetDesktopWindow()

// convert x, y, width and height from PBU to Pixels
lul_xpos   = UnitsToPixels(a_window.X, XUnitsToPixels!)
lul_ypos   = UnitsToPixels(a_window.Y, YUnitsToPixels!)
lul_width  = UnitsToPixels(a_window.width, XUnitsToPixels!)
lul_height = UnitsToPixels(a_window.height, YUnitsToPixels!)

Return this.of_Capture(lul_hWnd, &
					lul_xpos, lul_ypos, lul_width, &
					lul_height, ab_clipboard)

end function

public function string of_getlasterror ();// This function returns the most recent API error message

Constant ULong FORMAT_MESSAGE_FROM_SYSTEM = 4096
Constant ULong LANG_NEUTRAL = 0
ULong lul_rtn, lul_error
String ls_msgtext

lul_error = GetLastError()

ls_msgtext = Space(200)

lul_rtn = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, &
				lul_error, LANG_NEUTRAL, ls_msgtext, 200, 0)

Return ls_msgtext

end function

on n_bitmap.create
call super::create
TriggerEvent( this, "constructor" )
end on

on n_bitmap.destroy
TriggerEvent( this, "destructor" )
call super::destroy
end on

