#include "SceneInfo.h"

SceneInfo::SceneInfo(const nlohmann::json& o)
{
    jsonObj = o;
}

void SceneInfo::parseGeometries()
{
    std::string t;
    Eigen::Vector3f c;
    int r;
    Eigen::Vector3f aco;
    Eigen::Vector3f dco;
    Eigen::Vector3f sco;
    float kao, kdo, kso, pco;

    std::cout << "\nGeometry: " << std::endl;
    int gc = 0;

    // use iterators to read-in array types
    for (auto itr = jsonObj["geometry"].begin(); itr != jsonObj["geometry"].end(); itr++) {

        std::string type;
        if (itr->contains("type")) {
            // type = static_cast<std::string>((*itr)["type"]);
            type = (*itr)["type"].get<std::string>();
            t = type;
        }
        else {
            std::cout << "Fatal error: geometry shoudl always contain a type!!!" << std::endl;
        }

        if (type == "rectangle")
        {
            // Parameters
            Eigen::Vector3f p1(0, 0, 0);
            Eigen::Vector3f p2(0, 0, 0);
            Eigen::Vector3f p3(0, 0, 0);
            Eigen::Vector3f p4(0, 0, 0);
            Eigen::Vector3f ac(0, 0, 0);
            Eigen::Vector3f dc(0, 0, 0);
            Eigen::Vector3f sc(0, 0, 0);
            float ka, kd, ks, pc;
            int i = 0;

            // P1
            for (auto itr2 = (*itr)["p1"].begin(); itr2 != (*itr)["p1"].end(); itr2++) {
                if (i < 3) {
                    p1[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in p1" << std::endl;
                }
            }

            i = 0;
            // P2
            for (auto itr2 = (*itr)["p2"].begin(); itr2 != (*itr)["p2"].end(); itr2++) {
                if (i < 3) {
                    p2[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in p2" << std::endl;
                }
            }

            i = 0;
            // P3
            for (auto itr2 = (*itr)["p3"].begin(); itr2 != (*itr)["p3"].end(); itr2++) {
                if (i < 3) {
                    p3[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in p3" << std::endl;
                }
            }

            i = 0;
            // P4
            for (auto itr2 = (*itr)["p4"].begin(); itr2 != (*itr)["p4"].end(); itr2++) {
                if (i < 3) {
                    p4[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in p4" << std::endl;
                }
            }

            i = 0;
            // Ambient component
            for (auto itr2 = (*itr)["ac"].begin(); itr2 != (*itr)["ac"].end(); itr2++) {
                if (i < 3) {
                    ac[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in ac" << std::endl;
                }
            }

            i = 0;
            // Diffuse component
            for (auto itr2 = (*itr)["dc"].begin(); itr2 != (*itr)["dc"].end(); itr2++) {
                if (i < 3) {
                    dc[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in dc" << std::endl;
                }
            }

            i = 0;
            // Specular component
            for (auto itr2 = (*itr)["sc"].begin(); itr2 != (*itr)["sc"].end(); itr2++) {
                if (i < 3) {
                    sc[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in sc" << std::endl;
                }
            }

            // Ambient coefficient 
            for (auto itr2 = (*itr)["ka"].begin(); itr2 != (*itr)["ka"].end(); itr2++) {
                ka = (*itr2).get<float>();
            }

            // Diffuse coefficient 
            for (auto itr2 = (*itr)["kd"].begin(); itr2 != (*itr)["kd"].end(); itr2++) {
                kd = (*itr2).get<float>();
            }

            // Specular coefficient 
            for (auto itr2 = (*itr)["ks"].begin(); itr2 != (*itr)["ks"].end(); itr2++) {
                ks = (*itr2).get<float>();
            }

            // Specular highlight 
            for (auto itr2 = (*itr)["pc"].begin(); itr2 != (*itr)["pc"].end(); itr2++) {
                pc = (*itr2).get<float>();
            }

            this->rectangles.push_back(new Rectangle(p1, p2, p3, p4, ac, dc, sc, ka, kd, ks, pc));
            this->hittableObjects.push_back(std::unique_ptr<Object>(new Rectangle(p1, p2, p3, p4, ac, dc, sc, ka, kd, ks, pc)));
            ++gc;
        }

        else if (type == "sphere") {
            std::cout << "Sphere: " << std::endl;
            Eigen::Vector3f centre(0, 0, 0);
            int radius;
            Eigen::Vector3f ac(0, 0, 0);
            Eigen::Vector3f dc(0, 0, 0);
            Eigen::Vector3f sc(0, 0, 0);
            float ka, kd, ks, pc;
            
            int i = 0;
            // Centre
            for (auto itr2 = (*itr)["centre"].begin(); itr2 != (*itr)["centre"].end(); itr2++) {
                if (i < 3) {
                    centre[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in centre" << std::endl;
                }
            }

            i = 0;
            // Ambient component
            for (auto itr2 = (*itr)["ac"].begin(); itr2 != (*itr)["ac"].end(); itr2++) {
                if (i < 3) {
                    ac[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in ac" << std::endl;
                }
            }

            i = 0;
            // Diffuse component
            for (auto itr2 = (*itr)["dc"].begin(); itr2 != (*itr)["dc"].end(); itr2++) {
                if (i < 3) {
                    dc[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in dc" << std::endl;
                }
            }
            
            i = 0;
            // Specular component
            for (auto itr2 = (*itr)["sc"].begin(); itr2 != (*itr)["sc"].end(); itr2++) {
                if (i < 3) {
                    sc[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in sc" << std::endl;
                }
            }

            // Ambient coefficient 
            for (auto itr2 = (*itr)["ka"].begin(); itr2 != (*itr)["ka"].end(); itr2++) {
                ka = (*itr2).get<float>();
            }

            // Diffuse coefficient 
            for (auto itr2 = (*itr)["kd"].begin(); itr2 != (*itr)["kd"].end(); itr2++) {
                kd = (*itr2).get<float>();
            }

            // Specular coefficient 
            for (auto itr2 = (*itr)["ks"].begin(); itr2 != (*itr)["ks"].end(); itr2++) {
                ks = (*itr2).get<float>();
            }

            // Specular highlight 
            for (auto itr2 = (*itr)["pc"].begin(); itr2 != (*itr)["pc"].end(); itr2++) {
                pc = (*itr2).get<float>();
            }

            // Radius
            for (auto itr2 = (*itr)["radius"].begin(); itr2 != (*itr)["radius"].end(); itr2++) {
                radius = (*itr2).get<int>();
            }

            std::cout << "Centre: \n" << centre << std::endl;

            this->spheres.push_back(new Geometry(type, centre, radius, ac, dc, sc, ka, kd, ks, pc));
            this->hittableObjects.push_back(std::unique_ptr<Object>(new Sphere(type, centre, radius, ac, dc, sc, ka, kd, ks, pc)));
            ++gc;
        }
    }

    std::cout << "We have: " << gc << " objects!" << std::endl;
}

void SceneInfo::parseLights()
{
    std::cout << "\nLight: " << std::endl;
    int lc = 0;

    std::string t;
    Eigen::Vector3f c;
    Eigen::Vector3f d;
    Eigen::Vector3f s;

    // use iterators to read-in array types
    for (auto itr = jsonObj["light"].begin(); itr != jsonObj["light"].end(); itr++) {

        std::string type;
        if (itr->contains("type")) {
            //  type = static_cast<std::string>((*itr)["type"]);
            type = (*itr)["type"].get<std::string>();
            t = type;
        }
        else {
            std::cout << "Fatal error: light shoudl always contain a type!!!" << std::endl;
        }

        if (type == "point") {
            std::cout << "Point based light: " << std::endl;
            Eigen::Vector3f centre(0, 0, 0);
            Eigen::Vector3f diffuse(0, 0, 0);
            Eigen::Vector3f specular(0, 0, 0);
            
            int i = 0;
            // Get centre
            for (auto itr2 = (*itr)["centre"].begin(); itr2 != (*itr)["centre"].end(); itr2++) {
                if (i < 3) {
                    centre[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in centre" << std::endl;
                }
            }
            
            i = 0;
            // Get diffuse component
            for (auto itr2 = (*itr)["id"].begin(); itr2 != (*itr)["id"].end(); itr2++) {
                if (i < 3) {
                    diffuse[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in diffuse" << std::endl;
                }
            }

            i = 0;
            // Get specular component
            for (auto itr2 = (*itr)["is"].begin(); itr2 != (*itr)["is"].end(); itr2++) {
                if (i < 3) {
                    specular[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in specular" << std::endl;
                }
            }

            std::cout << "Centre: \n" << centre << std::endl;

            lights.push_back(new Light(t, centre, diffuse, specular));
            ++lc;
        }

        if (type == "area") {
            std::cout << "Area based light: " << std::endl;
            Eigen::Vector3f p1(0, 0, 0);
            Eigen::Vector3f p2(0, 0, 0);
            Eigen::Vector3f p3(0, 0, 0);
            Eigen::Vector3f p4(0, 0, 0);
            Eigen::Vector3f id(0, 0, 0);
            Eigen::Vector3f is(0, 0, 0);

            int i = 0;
            // Get p1 component
            for (auto itr2 = (*itr)["p1"].begin(); itr2 != (*itr)["p1"].end(); itr2++) {
                if (i < 3) {
                    p1[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in p1" << std::endl;
                }
            }

            i = 0;
            // Get p2 component
            for (auto itr2 = (*itr)["p2"].begin(); itr2 != (*itr)["p2"].end(); itr2++) {
                if (i < 3) {
                    p2[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in p2" << std::endl;
                }
            }

            i = 0;
            // Get p3 component
            for (auto itr2 = (*itr)["p3"].begin(); itr2 != (*itr)["p3"].end(); itr2++) {
                if (i < 3) {
                    p3[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in p3" << std::endl;
                }
            }

            i = 0;
            // Get p4 component
            for (auto itr2 = (*itr)["p4"].begin(); itr2 != (*itr)["p4"].end(); itr2++) {
                if (i < 3) {
                    p4[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in p4" << std::endl;
                }
            }

            i = 0;
            // Get id component
            for (auto itr2 = (*itr)["id"].begin(); itr2 != (*itr)["id"].end(); itr2++) {
                if (i < 3) {
                    id[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in id" << std::endl;
                }
            }

            i = 0;
            // Get is component
            for (auto itr2 = (*itr)["is"].begin(); itr2 != (*itr)["is"].end(); itr2++) {
                if (i < 3) {
                    is[i++] = (*itr2).get<float>();
                }
                else {
                    std::cout << "Warning: Too many entries in is" << std::endl;
                }
            }

            // Get usecenter component
            float useCentre = (*itr)["useCentre"].get<bool>();

            // Get n component
            float n = (*itr)["n"].get<float>();

            arealights.push_back(new AreaLight(p1, p2, p3, p4, id, is, useCentre, n));
            ++lc;
        }

    }

    std::cout << "We have: " << lc << " objects!" << std::endl;
}

void SceneInfo::parseOutput()
{
    std::cout << "\nOutputs: " << std::endl;
    int lc = 0;

    // use iterators to read-in array types
    for (auto itr = jsonObj["output"].begin(); itr != jsonObj["output"].end(); itr++) {

        std::string filename;
        if (itr->contains("filename")) {
            //  filename = static_cast<std::string>((*itr)["filename"]);
            filename = (*itr)["filename"].get<std::string>();
        }
        else {
            std::cout << "Fatal error: output shoudl always contain a filename!!!" << std::endl;
        }


        std::array<int, 2> size;
        int i = 0;
        for (auto itr2 = (*itr)["size"].begin(); itr2 != (*itr)["size"].end(); itr2++) {
            if (i < 2) {
                size[i++] = (*itr2).get<float>();
            }
            else {
                std::cout << "Warning: Too many entries in size" << std::endl;
            }
        }

        Eigen::Vector3f lookat(0, 0, 0), up(0, 0, 0), centre(0, 0, 0);
        Eigen::Vector3f ai(0, 0, 0);

        // Lookat
        i = 0;
        for (auto itr2 = (*itr)["lookat"].begin(); itr2 != (*itr)["lookat"].end(); itr2++) {
            if (i < 3) {
                lookat[i++] = (*itr2).get<float>();
            }
            else {
                std::cout << "Warning: Too many entries in lookat" << std::endl;
            }
        }

        // Up
        i = 0;
        for (auto itr2 = (*itr)["up"].begin(); itr2 != (*itr)["up"].end(); itr2++) {
            if (i < 3) {
                up[i++] = (*itr2).get<float>();
            }
            else {
                std::cout << "Warning: Too many entries in up" << std::endl;
            }
        }

        // Centre
        i = 0;
        for (auto itr2 = (*itr)["centre"].begin(); itr2 != (*itr)["centre"].end(); itr2++) {
            if (i < 3) {
                centre[i++] = (*itr2).get<float>();
            }
            else {
                std::cout << "Warning: Too many entries in centre" << std::endl;
            }
        }

        // Ambient intensity
        i = 0;
        for (auto itr2 = (*itr)["ai"].begin(); itr2 != (*itr)["ai"].end(); itr2++) {
            if (i < 3) {
                ai[i++] = (*itr2).get<float>();
            }
            else {
                std::cout << "Warning: Too many entries in ai" << std::endl;
            }
        }

        // Similarly to the centre array you need to read the lookat and up
        //Maybe create a separate functiomn to read arrays - ythey are pretty common


        // I am retrieving the field of view
        // this is mandatory field here, but if I dont check if it exists,
        // the code will throw an exception which if not caught will end the execution of yoru program
        float fov = (*itr)["fov"].get<float>();

        std::cout << "Filename: " << filename << std::endl;
        std::cout << "Dimensions: " << size[0] << ", " << size[1] << std::endl;
        std::cout << "Camera centre: \n" << centre << std::endl;
        std::cout << "Camera lookat: \n" << lookat << std::endl;
        std::cout << "Camera up: \n" << up << std::endl;
        std::cout << "FOV: " << fov << std::endl;

        output = new Output(filename, size, lookat, up, centre, fov, ai);

        ++lc;
    }

    std::cout << "We have: " << lc << " objects!" << std::endl;
}

void SceneInfo::parseAll()
{
    parseGeometries();
    parseLights();
    parseOutput();
}
