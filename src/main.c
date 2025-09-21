#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

typedef struct {
    char *data;
    size_t size;
    char *path;
} Sound;

typedef struct {
    Sound *soundData;
    int fileCount;
} ClickSounds;

ClickSounds clickSounds = { NULL, 0 };

static int loadFileIntoMemory(const char *path);
static void freeClickSounds();
void selectClickSounds();
void playClickSounds();

void playClickSounds() {
    if (clickSounds.fileCount > 0) {
        int index = rand() % clickSounds.fileCount;
        PlaySoundA(clickSounds.soundData[index].data, NULL, SND_MEMORY | SND_SYSTEM | SND_NOSTOP | SND_ASYNC);
    }
}

void selectClickSounds() {
    freeClickSounds();

    OPENFILENAME ofn;
    char szFile[MAX_PATH];

    ZeroMemory(&ofn, sizeof(ofn));
    ZeroMemory(szFile, sizeof(szFile));

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "WAV Files (*.wav)\0*.wav\0All Files (*.*)\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_ALLOWMULTISELECT | OFN_EXPLORER;

    if (GetOpenFileName(&ofn) == TRUE) {
        char *directory = ofn.lpstrFile;
    char *filePtr = directory + strlen(directory) + 1;

        if(*filePtr == '\0') {
            loadFileIntoMemory(directory);
        } else {
            while(*filePtr != '\0') {
                char filePath[MAX_PATH];
                sprintf(filePath, "%s\\%s", directory, filePtr);
                loadFileIntoMemory(filePath);
                filePtr += strlen(filePtr) + 1;
            }       
        }
    }
}

static int loadFileIntoMemory(const char *path) {
    FILE *targetFile = fopen(path, "rb");

    fseek(targetFile, 0, SEEK_END);
    size_t size = ftell(targetFile);
    rewind(targetFile);

    char *buffer = (char*)malloc(size);
    if (!buffer) {
        fclose(targetFile);
        return -1;
    }

    if (fread(buffer, 1, size, targetFile) != size) {
        free(buffer);
        fclose(targetFile);
        return -1;
    }
    fclose(targetFile);

    clickSounds.soundData = (Sound*)realloc(clickSounds.soundData, (clickSounds.fileCount + 1) * sizeof(Sound));
    if (!clickSounds.soundData) {
        free(buffer);
        return -1;
    }

    clickSounds.soundData[clickSounds.fileCount].data = buffer;
    clickSounds.soundData[clickSounds.fileCount].size = size;
    return clickSounds.fileCount++;
}

static void freeClickSounds() {
    for (int i = 0; i < clickSounds.fileCount; i++)
        free(clickSounds.soundData[i].data);
        
    free(clickSounds.soundData);
    clickSounds.soundData = NULL;
    clickSounds.fileCount = 0;
}

int main() {
    selectClickSounds();

    printf("Loaded %d files", clickSounds.fileCount);
    while(1) {
        if(GetAsyncKeyState(VK_LBUTTON) & 0x8000) playClickSounds();
        else PlaySoundA(NULL, NULL, SND_PURGE);

        Sleep(1);
    }
}