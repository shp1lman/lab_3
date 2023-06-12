#include <vector>
#include "framework.h"
#include "WindowsProject3.h"
#include "Resource.h"
#include <Windows.h>
 
#define MAX_LOADSTRING 100
 
namespace
{
 const int radius_ = 100;
}
class Vector2D {
public:
 float x, y;
 Vector2D(float x, float y) :x(x), y(y) {}
 friend Vector2D operator+(const Vector2D& v1, const Vector2D& v2) { return Vector2D(v1.x + v2.x, v1.y + v2.y); }
 friend Vector2D operator-(const Vector2D& v1, const Vector2D& v2) { return Vector2D(v1.x - v2.x, v1.y - v2.y); }
 friend Vector2D operator*(const Vector2D& v1, const Vector2D& v2) { return Vector2D(v1.x * v2.x, v1.y * v2.y); }
 friend Vector2D operator/(const Vector2D& v1, const Vector2D& v2) { return Vector2D(v1.x / v2.x, v1.y / v2.y); }
 Vector2D operator+=(const Vector2D& v) {
  x += v.x;
  y += v.y;
  return *this;
 }
 Vector2D operator-=(const Vector2D& v) {
  x -= v.x;
  y -= v.y;
  return *this;
 }
 Vector2D operator*=(float scale) {
  x *= scale;
  y *= scale;
  return *this;
 }
 Vector2D operator/=(float scale) {
  x /= scale;
  y /= scale;
  return *this;
 }
};
void DrawEllipse(HDC hdc, const Vector2D& pos, const Vector2D& size) {
 Ellipse(hdc, pos.x - size.x, pos.y - size.y, pos.x + size.x, pos.y + size.y);
}
HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowsClass[MAX_LOADSTRING];
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);
 
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
 _In_opt_ HINSTANCE hPrevInstance,
 _In_ LPWSTR lpCmdLine,
 _In_ int nCmdShow)
{
 UNREFERENCED_PARAMETER(hPrevInstance);
 UNREFERENCED_PARAMETER(lpCmdLine);
 
 LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
 LoadStringW(hInstance, IDC_WINDOWSPROJECT3, szWindowClass, MAX_LOADSTRING);
 MyRegisterClass(hInstance);
 
  
 if (!InitInstance(hInstance, nCmdShow))
 {
  return FALSE;
 }
 
 HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT3));
 
 MSG msg;
 
 
 while (GetMessage(&msg, nullptr, 0, 0))
 {
  if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
  {
   TranslateMessage(&msg);
   DispatchMessage(&msg);
  }
 }
 
 return (int)msg.wParam;
}
 
 
 
ATOM OwnRegisterClass(HINSTANCE hInstance)
{
 WNDCLASSEXW wcex;
 
 wcex.cbSize = sizeof(WNDCLASSEX);
 
 wcex.style = CS_HREDRAW | CS_VREDRAW;
 wcex.lpfnWndProc = WndProc;
 wcex.cbClsExtra = 0;
 wcex.cbWndExtra = 0;
 wcex.hInstance = hInstance;
 wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT3));
 wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
 wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
 wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT3);
 wcex.lpszClassName = szWindowClass;
 wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
 
 return RegisterClassExW(&wcex);
}
 
 
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
 hInst = hInstance; 
 HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
  CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
 
 if (!hWnd)
 {
  return FALSE;
 }
 
 ShowWindows(hWnd, nCmdShow);
 UpdateWindows(hWnd);
 
 return TRUE;
}
 
 
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
 switch (message)
 {
 case WM_COMMAND:
 {
  int wmId = LOWORD(wParam);
  switch (wmId)
  {
  case IDM_ABOUT:
   DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
   break;
  case IDM_EXIT:
   DestroyWindow(hWnd);
   break;
  default:
   return DefWindowsProc(hWnd, message, wParam, lParam);
  }
 }
 break;
 case WM_PAINT:
 {
  PAINTSTRUCT ps;
  HDC hdc = BeginPaint(hWnd, &ps);
  Vector2D V1(50, 50);
  Vector2D V3(40, 40);
  for (int i = 0; i < 3; ++i) {
   for (int j = 0; j < 3; j++) {
       radius_, j * radius_);
       DrawEll(hdc, V1 + V2, V3);
   }
  }
  EndDraw(hWnd, &ps);
  break;
 }
 case WM_DESTROY:
  PostQuitMessage(0);
  break;
 default:
  return DefWindowsProc(hWnd, message, wParam, lParam);
 }
 return 0;
}
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 UNREFERENCED_PARAMETER(lParam);
 switch (message)
 {
 case WM_INITDIALOG:
  return (INT_PTR)TRUE;
 
 case WM_COMMAND:
  if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
  {
   EndDialog(hDlg, LOWORD(wParam));
   return (INT_PTR)TRUE;
  }
  break;
 }
 return (INT_PTR)FALSE;
}
