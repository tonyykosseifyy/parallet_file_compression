#include "headers.h"

void compressSequentially(char *inputDir, char *outputDir) {
    char **filesList = listFiles(inputDir);
    int fileCount = countFiles(inputDir);
    printf('file count is %d\n', fileCount);


    struct timeval startTime, endTime;
    gettimeofday(&startTime, NULL);

    printf("Compressing files Sequentially\n");
    
    for (int i = 0; i < fileCount; i++) {
        compressFile(filesList[i], outputDir, i);
    }

    printf("\nCompression Finished.\n");

    gettimeofday(&endTime, NULL);
    
    double totalTime = (double)(endTime.tv_sec - startTime.tv_sec);
    
    printf("Total time taken to compress all files: ");
    formatTime(totalTime);


    cleanup(filesList);
}
