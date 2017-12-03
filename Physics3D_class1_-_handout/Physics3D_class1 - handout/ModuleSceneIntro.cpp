#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	// TODO 2: Place the camera one unit up in Y and one unit to the right
	// experiment with different camera placements, then use LookAt()
	// to make it look at the center
	vec3 x(1, 0, 0);
	vec3 y(0, 1, 0);
	vec3 z(0, 0, 1);
	vec3 xyz(4, 2, 4);
	vec3 zeroxyz(0, 0, 0);

	App->camera->Look(xyz, zeroxyz,true);


	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	// TODO 1: Create a Plane primitive. This uses the plane formula
	// so you have to express the normal of the plane to create 
	// a plane centered around 0,0. Make that it draw the axis for reference
	vec3 y(0, 1, 0);
	Plane Ground(0, 1, 0, 0);
	Ground.axis = true;
	Ground.Render();
	//Ground.normal = y;


	// TODO 6: Draw a sphere of 0.5f radius around the center
	// Draw somewhere else a cube and a cylinder in wireframe
	Sphere Pilotes(0.5f);
	Pilotes.Render();

	return UPDATE_CONTINUE;
}

