/*
 * Copyright 2019 Denis Salem
 *
 * This file is part of DStudio.
 *
 * DStudio is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * DStudio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with DStudio. If not, see <http://www.gnu.org/licenses/>.
*/

#include <dlfcn.h>
#include <GL/gl.h>

#define DSTUDIO_DEF_GL_FUN(ret, name, ...) typedef ret name##proc(__VA_ARGS__); name##proc * gl##name;

#define DSTUDIO_BIND_GL_FUN(name)                                 \
    gl##name = (name##proc *) dlsym(libGL, "gl" #name);           \
    if (!gl##name) {                                              \
        printf("gl" #name " couldn't be loaded from libGL.so\n"); \
        return -1;                                                \
    }
    
DSTUDIO_DEF_GL_FUN(void,            AttachShader,               GLuint program, GLuint shader)
DSTUDIO_DEF_GL_FUN(void,            BindBuffer,                 GLenum target, GLuint buffer)
DSTUDIO_DEF_GL_FUN(void,            BindVertexArray,            GLuint array)
DSTUDIO_DEF_GL_FUN(void,            BufferData,                 GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage)
DSTUDIO_DEF_GL_FUN(void,            BufferSubData,              GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data)
DSTUDIO_DEF_GL_FUN(void,            CompileShader,              GLuint shader) 
DSTUDIO_DEF_GL_FUN(GLuint,          CreateProgram)
DSTUDIO_DEF_GL_FUN(GLuint,          CreateShader,               GLenum shaderType)
DSTUDIO_DEF_GL_FUN(void,            DeleteProgram,              GLuint program)
DSTUDIO_DEF_GL_FUN(void,            DeleteShader,               GLuint shader)
DSTUDIO_DEF_GL_FUN(void,            DrawElementsInstanced,      GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount)
DSTUDIO_DEF_GL_FUN(void,            EnableVertexAttribArray,    GLuint index)
DSTUDIO_DEF_GL_FUN(void,            GenBuffers,                 GLsizei n, GLuint * buffers)
DSTUDIO_DEF_GL_FUN(void,            GenerateMipmap,             GLenum target)
DSTUDIO_DEF_GL_FUN(void,            GenVertexArrays,            GLsizei n, GLuint *arrays)
DSTUDIO_DEF_GL_FUN(GLint,           GetUniformLocation,         GLuint program, const GLchar *name)
DSTUDIO_DEF_GL_FUN(void,            LinkProgram,                GLuint program)
DSTUDIO_DEF_GL_FUN(void,            VertexAttribDivisor,        GLuint index, GLuint divisor)
DSTUDIO_DEF_GL_FUN(void,            VertexAttribPointer,        GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer)
DSTUDIO_DEF_GL_FUN(void,            UniformMatrix2fv,           GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
DSTUDIO_DEF_GL_FUN(void,            UseProgram,                 GLuint program)
DSTUDIO_DEF_GL_FUN(void,            ShaderSource,               GLuint shader, GLsizei count, const GLchar **string, const GLint *length)     

#ifdef DSTUDIO_DEBUG
DSTUDIO_DEF_GL_FUN(void,            GetProgramInfoLog,          GLuint program, GLsizei maxLength, GLsizei *length, GLchar *infoLog)
DSTUDIO_DEF_GL_FUN(void,            GetProgramiv,               GLuint program, GLenum pname, GLint *params)
DSTUDIO_DEF_GL_FUN(void,            GetShaderInfoLog,           GLuint shader, GLsizei maxLength, GLsizei *length, GLchar *infoLog)
DSTUDIO_DEF_GL_FUN(const GLubyte *, GetStringi,                 GLenum name, GLuint index)
#endif



int load_extensions();
