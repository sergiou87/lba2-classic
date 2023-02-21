#include <SYSTEM/adeline.h>

#include <AIL/midi.h>
#include <AIL/COMMON.H>

#include <stdlib.h>

#include <AIL/mssw.h>

// ████████████████████████████████████████████████████████████████████████████
HMDIDRIVER MdiDriver = NULL; // Handle to midi driver
S32 Midi_Driver_Enabled = FALSE;
S32 Midi_Driver_Type = MIDI;

HDIGDRIVER DigDriver = NULL; // Handle to digital audio driver
S32 Sample_Driver_Enabled = FALSE;
S32 SamplingRate = 22050;

char MidiDriverName[_MAX_PATH] = "";
char SampleDriverName[_MAX_PATH] = "";

// ████████████████████████████████████████████████████████████████████████████

VOID_FUNC *PauseMidiPtr = NULL;
VOID_FUNC *ResumeMidiPtr = NULL;

VOID_FUNC *PauseSamplesPtr = NULL;
VOID_FUNC *ResumeSamplesPtr = NULL;

// ████████████████████████████████████████████████████████████████████████████

void PauseBothMiles()
{
	(*PauseSamplesPtr)();
	(*PauseMidiPtr)();
}

// ████████████████████████████████████████████████████████████████████████████

void ResumeBothMiles()
{
	(*ResumeMidiPtr)();
	(*ResumeSamplesPtr)();
}

// ████████████████████████████████████████████████████████████████████████████
