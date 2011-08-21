#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if(argc<2)
  {
    printf("Too few arguments!\nTry: %s <packed-file>\n", argv[0]);
    exit(1);
  }

  int i;
  unsigned char x;
  FILE *from, *to;
  unsigned int offsets[16]=
  {
    0x00001e00, 0x0003651a, 0x004eb5df, 0x00875661,
    0x00ebeebe, 0x0129fb3a, 0x012d83d4, 0x016b9524,
    0x0172de4d, 0x01ad73fe, 0x01e3e955, 0x0269f60a,
    0x029b9d3a, 0x02e5387f, 0x031d67d8, 0x03715e5d
  };

  char names[15][30]=
  {
    "00levelcomplete.ogg",
    "01pushingonwards.ogg",
    "02positiveforce.ogg",
    "03potentialforanything.ogg",
    "04passionforexploring.ogg",
    "05intermission.ogg",
    "06presentingvvvvvv.ogg",
    "07gamecomplete.ogg",
    "08predestinedfate.ogg",
    "09positiveforcereversed.ogg",
    "10popularpotpourri.ogg",
    "11pipedream.ogg",
    "12pressurecooker.ogg",
    "13pacedenergy.ogg",
    "14piercingthesky.ogg"
  };

  from=fopen(argv[1], "r");
  for(i=0; i<15; i++)
  {
    to=fopen(names[i], "w");
    fseek(from, offsets[i], SEEK_SET);
    while(ftell(from)!=offsets[i+1])
    {
      fread(&x, 1, 1, from);
      fwrite(&x, 1, 1, to);
    }
    fclose(to);
  }
  fclose(from);

  return 0;
}