# __Gitlab Setting__

### 1. The username and password is your student id. Login to [GitLab (http://140.124.181.100)](http://140.124.181.100) and modify your password.
![](./img/gitlab/signIn.png)
### 2. Select "Create a project" to create a new project.
![](./img/gitlab/createProject1.png)
![](./img/gitlab/createProject2.png)

**Important**:
1. The project name must to be **\oop2025f_\${STUDENT_ID}_HW**.  
2. Set project visibility level as **private**.

![](./img/gitlab/createProject3.png)

### 3. Authorize TA to access your repository

1. Go to Members and search oop2025_TA
    ![](./img/gitlab/addTA1.png)
1. Choose *Maintainer* as role permission, and click invite  
    ![](./img/gitlab/addTA2.png)
1. You can find out There's 2 more members  


### 4. Set webhook

1. Go to **Setting -> Webhooks**<br>
    ![](./img/gitlab/webhooks1.png)

2. Fill in url as: "http://root:1161a7e2d616f4388e1e9b3d3737b485c9@140.124.181.97:8080/project/oop2025f_${STUDENT_ID}_HW"

3. Keep Secret Token as empty.

4. Select **Push events** in Trigger selection

5. Unselect **Enable SSL verification** in SSL verification.

6. Click "Add webhook"

    ![](./img/gitlab/webhooks2.png)
    ![](./img/gitlab/webhooks3.png)
