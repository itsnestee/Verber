//COLOR ASSETS
const nOffWhite = 0xfffaf9f6;
const nBlack = 0xff121212;

//Fonts
Engine.loadFontAs("{PROJECT_FOLDER}Fonts/LexendZetta-Medium.ttf", "Lexend");
Engine.setGlobalFont("Lexend");

//Panel
const var Panel1 = Content.getComponent("Panel1");

//BALL BEHAVIOUR ATTRIBUTES
var currentBallSize = 0;
const SIZE_SMOOTHER_ANIMATION = 0.93;
var initialOpacityAmount = 0.3;

//IMAGES
Panel1.loadImage("{PROJECT_FOLDER}BGF.png", "BGS");

//CABLE DATA
var cableGainAmount = 0;
global maxBallSize = 0;
const var gm = Engine.getGlobalRoutingManager();
const var cable = gm.getCable("gainValue");

inline function onCableChange(value){

	maxBallSize = value;
	cableGainAmount = value;
	
	if(btnIntelliverbPower.getValue() == 1)
	{
		VERBERV.setAttribute(VERBERV.VerbGate, 1 - (cableGainAmount * duckingAwareness));
		
	}
	else
	{
		VERBERV.setAttribute(VERBERV.VerbGate, 1);
		
	}
	

}

cable.registerCallback(onCableChange, false);

Panel1.setTimerCallback(function()
{	
	 if(Panel1.data.circleType == 1)
	 	initialOpacityAmount += 0.015;
	  	
	 if(initialOpacityAmount >= 1)
	 	initialOpacityAmount = 1;

	if(maxBallSize > currentBallSize)
		currentBallSize = maxBallSize;
	else
		currentBallSize *= SIZE_SMOOTHER_ANIMATION;
	
	if(currentBallSize < 0.001)
		currentBallSize = 0;
	
	 
 	Panel1.repaintImmediately();
});


inline function onIntelliverbPower(component, value)
{
	if(value == 1)
	{
		Panel1.data.circleType = 1;
		tempoSignature = 0;
		lbPredelayTempo.set("text", "OFF");
		btnPluPredelay.set("visible", 0);
		btnMinusPredelay.set("visible", 0);
		VERBERV.setAttribute(VERBERV.DelayTime, 0);
		VERBERV.setAttribute(VERBERV.Blend, Knob2.getValue() / 175);
		
	}
	else
	{
		Panel1.data.circleType = 0;
		initialOpacityAmount = 0.3;
		tempoSignature = 0;
		lbPredelayTempo.set("text", "None");
		btnPluPredelay.set("visible", 1);
		btnMinusPredelay.set("visible", 1);
		VERBERV.setAttribute(VERBERV.DelayTime, 0);
		VERBERV.setAttribute(VERBERV.Blend, Knob2.getValue() / 100);
	}
}

Panel1.setPaintRoutine(function(g)
{
	var tt = Content.getCurrentTooltip();
	
	g.drawImage("BGS", [0, 0, 600 , 600], 0, 0);
	g.setFont("Lexend", 60);
	g.setColour(nOffWhite);
	g.drawAlignedText("VERBER", [150, 40, 300, 50], "centred");
	
	//Tooltpip
	g.setFont("Lexend", 16);
	g.setColour(nOffWhite);
	g.drawAlignedText(tt, [50, 450, 500, 200], "centred");
	
	//Gradient Ball
	if(Panel1.data.circleType == 0){
		g.setGradientFill([0xFF0053CF, 0, 0, 0xFFB10180, this.getWidth(), this.getHeight()]);
		g.fillEllipse(this.getLocalBounds(160));
	}
	
	//White Ball
	if(Panel1.data.circleType == 1){
		g.setGradientFill([0xFFFaf9f6, 0, 0, 0x41FAF9F6, this.getWidth(), this.getHeight()]);
		g.setOpacity(initialOpacityAmount);
		g.fillEllipse(this.getLocalBounds(160 + (30 * currentBallSize)));
	}
	
});

Panel1.startTimer(50);

//POP UP MODIFICATIONS
Content.setValuePopupData({
    "itemColour":   0x07Faf9f6,    // BG colour TOP
    "itemColour2":  0x00Faf9f6, 		// BG colour BOTTOM
    "bgColour":     nOffWhite,      // In fact the Border colour...
    "borderSize":   0,
    "textColour":   0xFFFaf9f6,
    "fontSize":     16,
    "fontName":     "Lexend"
});

//OPEN INSTAGRAM
inline function openInstagram(component, value)
{
	if(value == 1)
	{
		Engine.openWebsite("https://www.instagram.com/itsnestee/");	
	}
};

