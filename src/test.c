#include <windows.h>

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

    switch (msg)
    {
    case WM_CREATE:
        MessageBox(NULL, L"Window was created", L"Info", MB_OK);
        break;
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
        break;
    }


    return 0;
}
static LPTSTR className = TEXT("Test Class");
static LPTSTR windowName = TEXT("Window Test");
int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPWSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wcex = { .cbSize = sizeof(WNDCLASSEX) };
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hInstance = hInst;
    wcex.lpfnWndProc = WindowProcedure;
    wcex.lpszClassName = className;
    wcex.lpszMenuName = NULL;
    wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    if(!RegisterClassEx(&wcex)) {
        MessageBoxW(NULL, L"Failed to register Window", L"Error", MB_OK);
        return 1;
    }
    HWND hWindow = CreateWindowEx(
        WS_EX_APPWINDOW, 
        className, windowName,
        (WS_OVERLAPPEDWINDOW | WS_BORDER) & ~(WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_THICKFRAME),
        100, 100, 640, 480, NULL, NULL, hInst, NULL);
    if(!hWindow) {
        MessageBoxW(NULL, L"Failed to create Window", L"Error", MB_OK);
        return 1;
    }
    ShowWindow(hWindow, nCmdShow);
    MSG msg;
    while(GetMessage(&msg, hWindow, 0, 0) != 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}