// Engine.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <Windows.h>
#include "Engine.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

LRESULT WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    // Zdefiniowanie nazwy klasy okna
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    // Zarejestrowanie klasy okna
    WNDCLASS wc = { };

    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Utworzenie okna
    HWND hwnd = CreateWindowEx(
        0,                              // Opcje rozszerzenia okna
        CLASS_NAME,                     // Nazwa klasy okna
        L"Sample Window",               // Tytuł okna
        WS_OVERLAPPEDWINDOW,            // Styl okna

        // Rozmiar i pozycja okna
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Okno nadrzędne
        NULL,       // Menu
        hInstance,  // Uchwyt do instancji
        NULL        // Dodatkowe dane aplikacji
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Pętla komunikatów
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
