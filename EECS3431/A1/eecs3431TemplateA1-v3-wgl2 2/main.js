
var canvas;
var gl;

var program ;

var near = -100;
var far = 100;


var left = -6.0;
var right = 6.0;
var ytop =6.0;
var bottom = -6.0;


var lightPosition2 = vec4(100.0, 100.0, 100.0, 1.0 );
var lightPosition = vec4(0.0, 0.0, 100.0, 1.0 );

var lightAmbient = vec4(0.2, 0.2, 0.2, 1.0 );
var lightDiffuse = vec4( 1.0, 1.0, 1.0, 1.0 );
var lightSpecular = vec4( 1.0, 1.0, 1.0, 1.0 );

var materialAmbient = vec4( 1.0, 0.0, 1.0, 1.0 );
var materialDiffuse = vec4( 1.0, 0.8, 0.0, 1.0 );
var materialSpecular = vec4( 0.4, 0.4, 0.4, 1.0 );
var materialShininess = 30.0;

var ambientColor, diffuseColor, specularColor;

var modelMatrix, viewMatrix, modelViewMatrix, projectionMatrix, normalMatrix;
var modelViewMatrixLoc, projectionMatrixLoc, normalMatrixLoc;
var eye;
var at = vec3(0.0, 0.0, 0.0);
var up = vec3(0.0, 1.0, 0.0);

var RX = 0 ;
var RY = 0 ;
var RZ = 0 ;

var MS = [] ; // The modeling matrix stack
var TIME = 0.0 ; // Realtime
var prevTime = 0.0 ;
var resetTimerFlag = true ;
var animFlag = false ;
var controller ;

function setColor(c)
{
    ambientProduct = mult(lightAmbient, c);
    diffuseProduct = mult(lightDiffuse, c);
    specularProduct = mult(lightSpecular, materialSpecular);

    gl.uniform4fv( gl.getUniformLocation(program,
                                         "ambientProduct"),flatten(ambientProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
                                         "diffuseProduct"),flatten(diffuseProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
                                         "specularProduct"),flatten(specularProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
                                         "lightPosition"),flatten(lightPosition) );
    gl.uniform1f( gl.getUniformLocation(program,
                                        "shininess"),materialShininess );
}

window.onload = function init() {

    canvas = document.getElementById( "gl-canvas" );

    gl = WebGLUtils.setupWebGL( canvas );
    if ( !gl ) { alert( "WebGL isn't available" ); }

    gl.viewport( 0, 0, canvas.width, canvas.height );
    gl.clearColor( 0.5, 0.5, 1.0, 1.0 );

    gl.enable(gl.DEPTH_TEST);

    //
    //  Load shaders and initialize attribute buffers
    //
    program = initShaders( gl, "vertex-shader", "fragment-shader" );
    gl.useProgram( program );


    setColor(materialDiffuse) ;

    Cube.init(program);
    Cylinder.init(9,program);
    Cone.init(9,program) ;
    Sphere.init(36,program) ;


    modelViewMatrixLoc = gl.getUniformLocation( program, "modelViewMatrix" );
    normalMatrixLoc = gl.getUniformLocation( program, "normalMatrix" );
    projectionMatrixLoc = gl.getUniformLocation( program, "projectionMatrix" );


    gl.uniform4fv( gl.getUniformLocation(program,
       "ambientProduct"),flatten(ambientProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
       "diffuseProduct"),flatten(diffuseProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
       "specularProduct"),flatten(specularProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
       "lightPosition"),flatten(lightPosition) );
    gl.uniform1f( gl.getUniformLocation(program,
       "shininess"),materialShininess );


	document.getElementById("sliderXi").oninput = function() {
		RX = this.value ;
		window.requestAnimFrame(render);
	}


    document.getElementById("sliderYi").oninput = function() {
        RY = this.value;
        window.requestAnimFrame(render);
    };
    document.getElementById("sliderZi").oninput = function() {
        RZ =  this.value;
        window.requestAnimFrame(render);
    };

    document.getElementById("animToggleButton").onclick = function() {
        if( animFlag ) {
            animFlag = false;
        }
        else {
            animFlag = true  ;
            resetTimerFlag = true ;
            window.requestAnimFrame(render);
        }
        console.log(animFlag) ;

		controller = new CameraController(canvas);
		controller.onchange = function(xRot,yRot) {
			RX = xRot ;
			RY = yRot ;
			window.requestAnimFrame(render); };
    };

    render();
}

// Sets the modelview and normal matrix in the shaders
function setMV() {
    modelViewMatrix = mult(viewMatrix,modelMatrix) ;
    gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(modelViewMatrix) );
    normalMatrix = inverseTranspose(modelViewMatrix) ;
    gl.uniformMatrix4fv(normalMatrixLoc, false, flatten(normalMatrix) );
}

// Sets the projection, modelview and normal matrix in the shaders
function setAllMatrices() {
    gl.uniformMatrix4fv(projectionMatrixLoc, false, flatten(projectionMatrix) );
    setMV() ;

}

// Draws a 2x2x2 cube center at the origin
// Sets the modelview matrix and the normal matrix of the global program
function drawCube() {
    setMV() ;
    Cube.draw() ;
}

// Draws a sphere centered at the origin of radius 1.0.
// Sets the modelview matrix and the normal matrix of the global program
function drawSphere() {
    setMV() ;
    Sphere.draw() ;
}
// Draws a cylinder along z of height 1 centered at the origin
// and radius 0.5.
// Sets the modelview matrix and the normal matrix of the global program
function drawCylinder() {
    setMV() ;
    Cylinder.draw() ;
}

// Draws a cone along z of height 1 centered at the origin
// and base radius 1.0.
// Sets the modelview matrix and the normal matrix of the global program
function drawCone() {
    setMV() ;
    Cone.draw() ;
}

// Post multiples the modelview matrix with a translation matrix
// and replaces the modeling matrix with the result
function gTranslate(x,y,z) {
    modelMatrix = mult(modelMatrix,translate([x,y,z])) ;
}

// Post multiples the modelview matrix with a rotation matrix
// and replaces the modeling matrix with the result
function gRotate(theta,x,y,z) {
    modelMatrix = mult(modelMatrix,rotate(theta,[x,y,z])) ;
}

// Post multiples the modelview matrix with a scaling matrix
// and replaces the modeling matrix with the result
function gScale(sx,sy,sz) {
    modelMatrix = mult(modelMatrix,scale(sx,sy,sz)) ;
}

// Pops MS and stores the result as the current modelMatrix
function gPop() {
    modelMatrix = MS.pop() ;
}

// pushes the current modelViewMatrix in the stack MS
function gPush() {
    MS.push(modelMatrix) ;
}

// Setting up a plane and 2 spheres
function setUpStaticObjects() {
  initStatePlane() ;
  initStateBigRock() ;
  initStateSmallRock() ;
  // initStateWorldCenterSphereForDebugging() ;
}

//
// Helper initializers for static objects
//
function initStateWorldCenterSphereForDebugging() {
  // World origin for debugging
  gPush() ;
  {
      setColor(vec4(0.2,0.3,0.7,1.0)) ;
      gScale(0.1, 0.1, 0.1) ;
      drawSphere() ;
  }
  gPop() ;
}

function initStatePlane() {
  // A plane - The bottom of sea
  gPush() ;
  {
    setColor(vec4(0.20, 0.20, 0.20 ,1.0)) ;
    gTranslate(0.0, -4.5, 0.0) ;
    gScale(6.0, 1.5, 0.0) ;
    drawCube() ;
  }
  gPop() ;
}

function initStateBigRock() {
  // A sphere - The big rock
  gPush() ;
  {
    setColor(vec4(0.30, 0.30, 0.30 ,1.0)) ;
    gTranslate(0.0, -2.2, 0.0) ;
    gScale(0.8, 0.8, 0.8)
    drawSphere();
  }
  gPop() ;
}

function initStateSmallRock() {
  // A sphere - The small rock
  gPush() ;
  {
    setColor(vec4(0.30, 0.30, 0.30 ,1.0)) ;
    gTranslate(-1.5, -2.6, 0.0) ;
    gScale(0.4, 0.4, 0.4) ;
    drawSphere();
  }
  gPop() ;
}

//
// Helper initializers for dynamic objects
//
function initStateFishHead() {
  setColor(vec4(0.5,0.5,0.5,1.0)) ;
  gRotate(90, 0.0, 1.0, 0.0) ;
  gScale(0.9, 0.9, 0.9) ;
  drawCone() ;
}

function initStateFishBody() {
  setColor(vec4(1.0,0.0,0.0,1.0)) ;
  gTranslate(-1.9, 0.0, 0.0) ;
  gScale(3.0, 1.0, 1.0) ;
  gRotate(-90, 0.0, 1.0, 0.0) ;
  drawCone() ;
}

// Two eyes are identical
// Right eye needs to be at -3.5 in z-axis
// Right eye needs to be at -4.5 in z-axis
function initStateFishtEye(zIndex) {
  setColor(vec4(1.0, 1.0, 1.0 ,1.0)) ;
  gTranslate(0.0, 0.2, zIndex) ;
  gScale(0.175, 0.175, 0.175) ;
  drawSphere() ;
}

function initStateFishEyeBall(zIndex) {
  setColor(vec4(0.0, 0.0, 0.0 ,1.0)) ;
  gTranslate(0.1, 0.2, zIndex) ;
  gScale(0.112, 0.112, 0.112) ;
  drawSphere() ;
}

function initStateFishTailLarge() {
  setColor(vec4(1.0, 0.0, 0.0 ,1.0)) ;
  gTranslate(-3.2, -1.2, -4.0) ;
  gRotate(45*Math.sin(7*TIME), 0.0, 1.0, 0.0) ;
  gTranslate(-0.8, 0.9, 0.0) ;
  gRotate(-45, 0.0, 0.0, 1.0) ;
  gRotate(-90, 0.0, 1.0, 0.0) ;
  gScale(0.2, 0.2 ,2.0) ;
  drawCone() ;
}

function initStateFishTailSmall() {
  setColor(vec4(1.0, 0.0, 0.0 ,1.0)) ;
  gTranslate(-3.1, -0.9, -4.0) ;
  gRotate(45*Math.sin(7*TIME), 0.0, 1.0, 0.0) ;
  gTranslate(-0.5, -0.5, 0.0) ;
  gRotate(45, 0.0, 0.0, 1.0) ;
  gRotate(-90, 0.0, 1.0, 0.0) ;
  gScale(0.15, 0.15 ,1.0) ;
  drawCone() ;
}

//
// Helper Animation Functions
//
function applyCircularRotationFishBody() {
  applyFishRotationAndTranslationFishRelated() ;
  gTranslate(0.0, 0.0, -4.0) ;
}

function applyCircularRotationFishEyes() {
  applyFishRotationAndTranslationFishRelated() ;
}

function applyFishRotationAndTranslationFishRelated() {
  gTranslate(0.0, -1, 0.0) ;
  gRotate(55*TIME, 0.0, -1.0, 0.0) ;
}



function animateFish() {

  gPush() ;
  {
    gTranslate(0.0, -0.5*Math.sin(TIME), 0.0) ; // Make the fish ossiliate as it rotates
    gTranslate(0.0, -1.0, 0.0) ;
    gScale(0.5, 0.5, 0.5) ; // Make the fish smaller than originally planned

    // Bigger tail
    gPush() ;
    {
      gRotate(55*TIME, 0.0, -1.0, 0.0) ;
      initStateFishTailLarge() ;
    }
    gPop() ;

    // Smaller tail
    gPush() ;
    {
      gRotate(55*TIME, 0.0, -1.0, 0.0) ;
      initStateFishTailSmall() ;
    }
    gPop() ;

    // Fish Head
    gPush() ;
    {
      applyCircularRotationFishBody() ;
      initStateFishHead() ;

    }
    gPop() ;

    // Fish Body
    gPush() ;
    {
      applyCircularRotationFishBody() ;
      initStateFishBody() ;
    }
    gPop() ;

    // Fish right eye
    gPush() ;
    {
      applyCircularRotationFishEyes() ;
      initStateFishtEye(-3.5) ;
    }
    gPop() ;

    // Fish right eyeball
    gPush() ;
    {
      applyCircularRotationFishEyes() ;
      initStateFishEyeBall(-3.5) ;
    }
    gPop() ;

    // Fish left eye
    gPush() ;
    {
      applyCircularRotationFishEyes() ;
      initStateFishtEye(-4.5) ;
    }
    gPop() ;

    // Fish left eyeball
    gPush() ;
    {
      applyCircularRotationFishEyes() ;
      initStateFishEyeBall(-4.5) ;
    }
    gPop() ;
  }
  gPop() ;
}

function drawSeaWeedParticle() {
  gPush() ;
  {
    gTranslate(0.0, -1.09, 0.0) ;
    setColor(vec4(0.0, 0.6, 0.0 ,1.0)) ;
    gScale(0.12, 0.30, 0.12) ;
    drawSphere() ;
  }
  gPop() ;
}

function drawSeaWeedStrawCenter() {
  for (var i = 0; i < 8; i++) {
    gPush() ;
    {
      gTranslate(0.0, i*0.6, 0.0) ;
      drawSeaWeedParticle() ;
    }
    gPop() ;
  }
}

function animateSeaWeed() {
  gPush() ;
  {
    gPush() ;
    {
      drawSeaWeedStrawCenter() ;
    }
    gPop() ;

    gPush() ;
    {
      gTranslate(0.7, -0.5, 0.0) ;
      drawSeaWeedStrawCenter() ;
    }
    gPop() ;

    gPush() ;
    {
      gTranslate(-0.7, -0.5, 0.0) ;
      drawSeaWeedStrawCenter() ;
    }
    gPop() ;
  }
  gPop() ;
}

function generateBubble(offsetY) {
  gPush() ;
  {
    setColor(vec4(0.8, 1.0, 1.0 ,1.0)) ;
    gTranslate(0.5*Math.sin(TIME), 0.5*Math.sin(TIME), 0.0) ;
    gTranslate(0.0, 0.7*TIME, 0.0) ;
    gTranslate(4.2, 1.3 + offsetY, 0.1) ;
    gScale(0.07, 0.090, 0.090) ;
    drawSphere() ;
  }
  gPop() ;
}

function generateBubbleLoc(locaX, locY, locZ) {
  gPush() ;
  {
    setColor(vec4(0.8, 1.0, 1.0 ,1.0)) ;
    gTranslate(0.5*Math.sin(TIME), 0.5*Math.sin(TIME), 0.0) ;
    gTranslate(0.0, 0.7*TIME, 0.0) ;
    gTranslate(locaX, locY, locZ) ;
    gScale(0.07, 0.090, 0.090) ;
    drawSphere() ;
  }
  gPop() ;
}


function drawPersonHead() {
  gPush() ;
  {
    setColor(vec4(0.5, 0.0, 0.5 ,1.0)) ;
    gTranslate(4.2, 2.2, 0.0) ;
    gScale(0.4, 0.4, 0.4) ;
    drawSphere() ;
  }
  gPop() ;
}

function drawPersonBody() {
  gPush() ;
  {
    setColor(vec4(0.5, 0.0, 0.5 ,1.0)) ;
    gTranslate(4.2, 0.6, 0.0) ;
    gRotate(-30, 0.0, 1.0, 0.0) ;
    gScale(0.8, 1.2, 0.3) ;
    drawCube ();
  }
  gPop() ;
}

function drawAnimatedSingleSeaWeed() {
  gPush() ;
  {
    gTranslate(-0.1*Math.sin(2*TIME), 0.0, 0.0) ;
    gTranslate(0.18, 3.30, 0.0) ;
    gRotate(20, 0.0, 0.0, 1.0) ;
    setColor(vec4(0.0, 0.6, 0.0 ,1.0)) ;
    gScale(0.12, 0.25, 0.12) ;
    drawSphere() ;
  }
  gPop() ;
  gPush() ;
  {
    gTranslate(-0.1*Math.sin(2*TIME), 0.0, 0.0) ;
    gTranslate(0.30, 2.80, 0.0) ;
    gRotate(10, 0.0, 0.0, 1.0) ;
    setColor(vec4(0.0, 0.6, 0.0 ,1.0)) ;
    gScale(0.12, 0.25, 0.12) ;
    drawSphere() ;
  }
  gPop() ;
  gPush() ;
  {
    gTranslate(-0.1*Math.sin(2*TIME), 0.0, 0.0) ;
    gTranslate(0.25, 2.32, 0.0) ;
    gRotate(-30, 0.0, 0.0, 1.0) ;
    setColor(vec4(0.0, 0.6, 0.0 ,1.0)) ;
    gScale(0.12, 0.25, 0.12) ;
    drawSphere() ;
  }
  gPop() ;
  gPush() ;
  {
    gTranslate(-0.1*Math.sin(2*TIME), 0.0, 0.0) ;
    gTranslate(0.05, 1.85, 0.0) ;
    gRotate(-20, 0.0, 0.0, 1.0) ;
    setColor(vec4(0.0, 0.6, 0.0 ,1.0)) ;
    gScale(0.12, 0.25, 0.12) ;
    drawSphere() ;
  }
  gPop() ;
  gPush() ;
  {
    gTranslate(-0.1*Math.sin(2*TIME), 0.0, 0.0) ;
    gTranslate(-0.05, 1.35, 0.0) ;
    gRotate(-10, 0.0, 0.0, 1.0) ;
    setColor(vec4(0.0, 0.6, 0.0 ,1.0)) ;
    gScale(0.12, 0.25, 0.12) ;
    drawSphere() ;
  }
  gPop() ;
  gPush() ;
  {
    gTranslate(-0.1*Math.sin(2*TIME), 0.0, 0.0) ;
    gTranslate(-0.05, 0.85, 0.0) ;
    gRotate(10, 0.0, 0.0, 1.0) ;
    setColor(vec4(0.0, 0.6, 0.0 ,1.0)) ;
    gScale(0.12, 0.25, 0.12) ;
    drawSphere() ;
  }
  gPop() ;
  gPush() ;
  {
    gTranslate(-0.1*Math.sin(2*TIME), 0.0, 0.0) ;
    gTranslate(-0.05, 0.35, 0.0) ;
    gRotate(-10, 0.0, 0.0, 1.0) ;
    setColor(vec4(0.0, 0.6, 0.0 ,1.0)) ;
    gScale(0.12, 0.25, 0.12) ;
    drawSphere() ;
  }
  gPop() ;
  gPush() ;
  {
    gTranslate(-0.1*Math.sin(2*TIME), 0.0, 0.0) ;
    gTranslate(-0.05, -0.15, 0.0) ;
    gRotate(10, 0.0, 0.0, 1.0) ;
    setColor(vec4(0.0, 0.6, 0.0 ,1.0)) ;
    gScale(0.12, 0.25, 0.12) ;
    drawSphere() ;
  }
  gPop() ;
  gPush() ;
  {
    gTranslate(0.0, -0.95, 0.0) ;
    gRotate(10*Math.sin(2*TIME), 0.0, 0.0, 1.0) ;
    gTranslate(0.0, 0.3, 0.0) ;
    setColor(vec4(0.0, 0.6, 0.0 ,1.0)) ;
    gScale(0.12, 0.25, 0.12) ;
    drawSphere() ;
  }
  gPop() ;
  gPush() ;
  {
    gTranslate(0.0, -1.15, 0.0) ;
    setColor(vec4(0.0, 0.6, 0.0 ,1.0)) ;
    gScale(0.12, 0.25, 0.12) ;
    drawSphere() ;
  }
  gPop() ;
}

function drawPersonLeg(locX, locY, locZ, isRightLeg) {
  gPush() ;
  {

    gTranslate(locX,locY, locZ) ;
    if (isRightLeg) {
      gRotate(15*Math.sin(2*TIME), 1.0, 0.0, 0.0) ;
    }
    else {
      gRotate(-15*Math.sin(2*TIME), 1.0, 0.0, 0.0) ;
    }

    // Foot
    gPush() ;
    {
      setColor(vec4(0.5, 0.0, 0.5 ,1.0)) ;
      gTranslate(0.9, -1.1, -1.5) ;
      gRotate(-30, 0.0, 1.0, 0.0) ;
      gRotate(75, 1.0, 0.0, 0.0) ;
      gScale(0.2, 0.1, 0.4) ;
      drawCube() ;
    }
    gPop() ;

    // lower leg
    gPush() ;
    {
      setColor(vec4(0.5, 0.0, 0.5 ,1.0)) ;
      gTranslate(0.5, -0.8, -0.9) ;
      gRotate(-30, 0.0, 1.0, 0.0) ;
      gRotate(75, 1.0, 0.0, 0.0) ;
      gScale(0.2, 0.7, 0.2) ;
      drawCube() ;
    }
    gPop() ;

    // thy
    gPush() ;
    {
      setColor(vec4(0.5, 0.0, 0.5 ,1.0)) ;
      gRotate(-30, 0.0, 1.0, 0.0) ;
      gRotate(30, 1.0, 0.0, 0.0) ;
      gScale(0.2, 0.7, 0.2) ;
      drawCube() ;
    }
    gPop() ;
  }
  gPop() ;
}

function animatePerson() {
  gPush() ;
  {
    gTranslate(0.5*Math.sin(TIME), 0.5*Math.sin(TIME), 0.0) ;
    gTranslate(1.7, 0.0, 0.0) ;

    gScale(0.6, 0.6, 0.6) ;
    drawPersonHead() ;
    drawPersonBody() ;
    drawPersonLeg(3.9, -1.1, -0.5, true) ;
    drawPersonLeg(4.8, -1.1, 0.0, false) ;
  }
  gPop() ;
}

function animateSeaWeed() {
  gPush() ;
  {
    drawAnimatedSingleSeaWeed() ;

    gPush() ;
    {
      gTranslate(0.8, -0.8, 0.0) ;
      drawAnimatedSingleSeaWeed() ;
    }
    gPop() ;

    gPush() ;
    {
      gTranslate(-0.8, -0.8, 0.0) ;
      drawAnimatedSingleSeaWeed() ;
    }
    gPop() ;
  }
  gPop();
}

function render() {

    gl.clear( gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

    eye = vec3(0,0,10);
    MS = [] ; // Initialize modeling matrix stack

	// initialize the modeling matrix to identity
    modelMatrix = mat4() ;

    // set the camera matrix
    viewMatrix = lookAt(eye, at , up);

    // set the projection matrix
    projectionMatrix = ortho(left, right, bottom, ytop, near, far);

    // Rotations from the sliders
    gRotate(RZ,0,0,1) ;
    gRotate(RY,0,1,0) ;
    gRotate(RX,1,0,0) ;

    // set all the matrices
    setAllMatrices() ;

    var curTime ;
    if( animFlag )
    {
        curTime = (new Date()).getTime() /1000 ;
        if( resetTimerFlag ) {
            prevTime = curTime ;
            resetTimerFlag = false ;
        }

        TIME = TIME + curTime - prevTime ;
        prevTime = curTime ;
    }

    setUpStaticObjects();
    animateFish() ;
    animatePerson() ;
    animateSeaWeed() ;



    gPush() ;
    {
      generateBubble(0.2) ;
      generateBubble(0.3) ;
      generateBubble(0.5) ;

    }
    gPop() ;


    if( animFlag )
        window.requestAnimFrame(render);
}

// A simple camera controller which uses an HTML element as the event
// source for constructing a view matrix. Assign an "onchange"
// function to the controller as follows to receive the updated X and
// Y angles for the camera:
//
//   var controller = new CameraController(canvas);
//   controller.onchange = function(xRot, yRot) { ... };
//
// The view matrix is computed elsewhere.
function CameraController(element) {
	var controller = this;
	this.onchange = null;
	this.xRot = 0;
	this.yRot = 0;
	this.scaleFactor = 3.0;
	this.dragging = false;
	this.curX = 0;
	this.curY = 0;

	// Assign a mouse down handler to the HTML element.
	element.onmousedown = function(ev) {
		controller.dragging = true;
		controller.curX = ev.clientX;
		controller.curY = ev.clientY;
	};

	// Assign a mouse up handler to the HTML element.
	element.onmouseup = function(ev) {
		controller.dragging = false;
	};

	// Assign a mouse move handler to the HTML element.
	element.onmousemove = function(ev) {
		if (controller.dragging) {
			// Determine how far we have moved since the last mouse move
			// event.
			var curX = ev.clientX;
			var curY = ev.clientY;
			var deltaX = (controller.curX - curX) / controller.scaleFactor;
			var deltaY = (controller.curY - curY) / controller.scaleFactor;
			controller.curX = curX;
			controller.curY = curY;
			// Update the X and Y rotation angles based on the mouse motion.
			controller.yRot = (controller.yRot + deltaX) % 360;
			controller.xRot = (controller.xRot + deltaY);
			// Clamp the X rotation to prevent the camera from going upside
			// down.
			if (controller.xRot < -90) {
				controller.xRot = -90;
			} else if (controller.xRot > 90) {
				controller.xRot = 90;
			}
			// Send the onchange event to any listener.
			if (controller.onchange != null) {
				controller.onchange(controller.xRot, controller.yRot);
			}
		}
	};
}
